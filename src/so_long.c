#include "so_long.h"

typedef struct s_collisions
{
	int	x;
	int	y;
	int	size;
	int	type;
	struct s_collisions *next;
}	t_collisions;


typedef struct s_game
{
	mlx_t			*mlx;
	t_map_info		map;
	t_collisions	*list_box;
	mlx_image_t		*player;
}	t_game;

t_game	init_game(mlx_t **mlx, t_map_info map, t_collisions **list_box)
{
	t_game	result;

	result.mlx = *mlx;
	result.map = map;
	result.list_box = *list_box;
	result.player = NULL;
	return (result);
}

void add_stock(t_collisions **stock, int x, int y, int size, int type)
{
    t_collisions *new_collision = (t_collisions *)malloc(sizeof(t_collisions));
    if (new_collision == NULL)
        return;

    new_collision->x = x;
    new_collision->y = y;
    new_collision->size = size;
    new_collision->type = type;
    new_collision->next = *stock;
    *stock = new_collision;
}

mlx_image_t	*resize_img(mlx_image_t	*img, int zoom)
{
	mlx_resize_image(img, img->width * zoom, img->width * zoom);
	return (img);
}

t_collisions	*display_map(t_map_info map, mlx_t **mlx_a)
{
	t_collisions	*result;
	int				x;
	int				y;
	mlx_image_t*    img;
	mlx_t			*mlx;

	mlx = *mlx_a;
	result = NULL;
	y = 0;
	while (y < map.y)
	{
		x = 0;
		while (x < map.x)
		{
			mlx_image_to_window(mlx, resize_img(mlx_texture_to_image(mlx, mlx_load_png("./assets/background.png")), 4), x * 64, y * 64);
			if (map.map[y][x] == '1')
			{
				img = mlx_texture_to_image(mlx, mlx_load_png("./assets/wall.png"));
				add_stock(&result, x * 64, y * 64, 64, 1);
			}
			else if (map.map[y][x] == 'C')
			{
				img = mlx_texture_to_image(mlx, mlx_load_png("./assets/collectible.png"));
				add_stock(&result, x * 64, y * 64, 64, 2);
			}
			else if (map.map[y][x] == 'E')
			{
				img = mlx_texture_to_image(mlx, mlx_load_png("./assets/exit.png"));
				add_stock(&result, x * 64, y * 64, 64, 3);
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
				img = mlx_texture_to_image(mlx, mlx_load_png("./assets/character.png"));
				mlx_image_to_window(mlx, resize_img(img, 4), x * 64, y * 64);
				game->player = img;
			}
			x++;
		}
		y++;
	}
}

static	int	check_collision(int y, int x, t_game *param)
{
	t_collisions	*temp;

	temp = param->list_box;
	while (temp)
	{
		if (!(y + param->player->height \
		<= (unsigned int)temp->y \
		|| y >= temp->y + 68 \
		|| x + param->player->width <= \
		(unsigned int)temp->x \
		|| x >= temp->x + 68))
			if (temp->type == 1)
				return (0);
		temp = temp->next;
	}
	return (1);
}

void	hook(void *param)
{
	t_game *params = (t_game *)param;
	t_collisions *current;
	int	x;
	int y;

	y = params->player->instances[0].y;
	x = params->player->instances[0].x;
	if (mlx_is_key_down(params->mlx, MLX_KEY_D) && check_collision(y, x + 8, params))
		params->player->instances[0].x += 8;
	if (mlx_is_key_down(params->mlx, MLX_KEY_A) && check_collision(y, x - 8, params))
		params->player->instances[0].x -= 8;
	if (mlx_is_key_down(params->mlx, MLX_KEY_W) && check_collision(y - 8, x, params))
		params->player->instances[0].y -= 8;
	if (mlx_is_key_down(params->mlx, MLX_KEY_S) && check_collision(y + 8, x, params))
		params->player->instances[0].y += 8;
	if (mlx_is_key_down(params->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(params->mlx);
}

int32_t main(void)
{
	mlx_t			*mlx;
	t_map_info		map;
	t_collisions	*list_box;
	t_game			game;

	list_box = NULL;
	map = get_array_map("./maps/map.ber");
	mlx = mlx_init(64 * map.x, 64 * map.y, "so_long", false);
	list_box = display_map(map, &mlx);
	game = init_game(&mlx, map, &list_box);
	spawn_player(map, &game, &mlx);
	mlx_loop_hook(mlx, hook, &game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}