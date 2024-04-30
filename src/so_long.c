#include "so_long.h"

typedef struct s_collisions
{
	mlx_image_t			*sprite;
	int					type;
	int					is_collected;
	struct s_collisions	*next;
}						t_collisions;

typedef struct s_game
{
	mlx_t				*mlx;
	t_map_info			map;
	t_collisions		*list_box;
	mlx_image_t			*player;
	int					collect;
}						t_game;

t_game	init_game(mlx_t **mlx, t_map_info map, t_collisions **list_box)
{
	t_game	result;

	result.mlx = *mlx;
	result.map = map;
	result.list_box = *list_box;
	result.player = NULL;
	result.collect = 0;
	return (result);
}

void	add_stock(t_collisions **stock, mlx_image_t *sprite, int type)
{
	t_collisions	*new_collision;

	new_collision = (t_collisions *)malloc(sizeof(t_collisions));
	if (new_collision == NULL)
		return ;
	new_collision->sprite = sprite;
	new_collision->type = type;
	new_collision->is_collected = 0;
	new_collision->next = *stock;
	*stock = new_collision;
}

#include <stdio.h>

static int	check_collision(int y, int x, t_game *param)
{
	t_collisions	*temp;

	temp = param->list_box;
	while (temp)
	{
		if (!(y + param->player->height <= temp->sprite->instances[0].y
				|| y >= temp->sprite->instances[0].y + temp->sprite->height || x
				+ param->player->width <= temp->sprite->instances[0].x
				|| x >= temp->sprite->instances[0].x + temp->sprite->width))
		{
			if (temp->type == 1)
				return (0);
			if (temp->type == 2 && temp->is_collected == 0)
			{
				temp->is_collected = 1;
				temp->sprite->instances[0].enabled = false;
				param->collect++;
				return (1);
			}
			if (temp->type == 3
				&& param->collect == param->map.collectible_count)
			{
				mlx_close_window(param->mlx);
				return (1);
			}
		}
		temp = temp->next;
	}
	return (1);
}

mlx_image_t	*resize_img(mlx_image_t *img, int zoom)
{
	mlx_resize_image(img, img->width * zoom, img->width * zoom);
	return (img);
}

t_collisions	*display_map(t_map_info map, mlx_t **mlx_a)
{
	t_collisions	*result;
	int				x;
	int				y;
	mlx_image_t		*img;
	mlx_t			*mlx;

	mlx = *mlx_a;
	result = NULL;
	y = 0;
	while (y < map.y)
	{
		x = 0;
		while (x < map.x)
		{
			mlx_image_to_window(mlx, resize_img(mlx_texture_to_image(mlx,
						mlx_load_png("./assets/background.png")), 4), x * 64, y
				* 64);
			if (map.map[y][x] == '1')
			{
				img = mlx_texture_to_image(mlx,
						mlx_load_png("./assets/wall.png"));
				add_stock(&result, img, 1);
			}
			else if (map.map[y][x] == 'C')
			{
				img = mlx_texture_to_image(mlx,
						mlx_load_png("./assets/collectible.png"));
				add_stock(&result, img, 2);
			}
			else if (map.map[y][x] == 'E')
			{
				img = mlx_texture_to_image(mlx,
						mlx_load_png("./assets/exit.png"));
				add_stock(&result, img, 3);
			}
			else
				img = NULL;
			if (img != NULL)
			{
				mlx_image_to_window(mlx, resize_img(img, 4), x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
	return (result);
}

void	spawn_player(t_map_info map, t_game *game, mlx_t **mlx_a)
{
	int			x;
	int			y;
	mlx_image_t	*img;
	mlx_t		*mlx;

	mlx = *mlx_a;
	y = 0;
	while (y < map.y)
	{
		x = 0;
		while (x < map.x)
		{
			if (map.map[y][x] == 'P')
			{
				img = mlx_texture_to_image(mlx,
						mlx_load_png("./assets/character.png"));
				mlx_image_to_window(mlx, resize_img(img, 3), x * 64, y * 64);
				game->player = img;
			}
			x++;
		}
		y++;
	}
}

void	hook(void *param)
{
	t_game			*params;
	t_collisions	*current;
	int				x;
	int				y;

	params = (t_game *)param;
	y = params->player->instances[0].y;
	x = params->player->instances[0].x;
	if (mlx_is_key_down(params->mlx, MLX_KEY_D) && check_collision(y, x + 8,
			params))
		params->player->instances[0].x += 8;
	if (mlx_is_key_down(params->mlx, MLX_KEY_A) && check_collision(y, x - 8,
			params))
		params->player->instances[0].x -= 8;
	if (mlx_is_key_down(params->mlx, MLX_KEY_W) && check_collision(y - 8, x,
			params))
		params->player->instances[0].y -= 8;
	if (mlx_is_key_down(params->mlx, MLX_KEY_S) && check_collision(y + 8, x,
			params))
		params->player->instances[0].y += 8;
	if (mlx_is_key_down(params->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(params->mlx);
	ft_printf("Nombres de pas:", ((x + y) / 8));
}

int32_t	main(int argc, char **argv)
{
	mlx_t *mlx;
	t_map_info map;
	t_collisions *list_box;
	t_game game;

	list_box = NULL;
	map = get_array_map(argv[1]);
	mlx = mlx_init(64 * map.x, 64 * map.y, "so_long", false);
	list_box = display_map(map, &mlx);
	game = init_game(&mlx, map, &list_box);
	spawn_player(map, &game, &mlx);
	mlx_loop_hook(mlx, hook, &game);
	mlx_loop(mlx);
	destroy_map(&map);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}