#include "so_long.h"

typedef struct s_game
{
	int				direction;
	int				x_e;
	int				y_e;
	mlx_t			*mlx;
	mlx_texture_t	*player_texture;
	mlx_image_t		*player;
	mlx_texture_t	*background_texture;
	mlx_image_t		*background;
	mlx_texture_t	*collectible_texture;
	mlx_image_t		*collectible;
	mlx_texture_t	*exit_texture;
	mlx_image_t		*exit;
	mlx_texture_t	*wall_texture;
	mlx_image_t		*wall;
	t_map_info		*map;
}					t_game;

void	init_draw(t_game **game, t_map_info **map)
{
	(*game)->collectible_texture = mlx_load_png("./assets/collectible.png");
	if (!(*game)->collectible_texture)
		errors_controller("Erreur d'allocations mémoires\n", *map);
	(*game)->collectible = mlx_texture_to_image((*game)->mlx,
			(*game)->collectible_texture);
	if (!(*game)->collectible)
		errors_controller("Erreur d'allocations MLX\n", *map);
	(*game)->exit_texture = mlx_load_png("./assets/exit.png");
	if (!(*game)->exit_texture)
		errors_controller("Erreur d'allocations mémoires\n", *map);
	(*game)->exit = mlx_texture_to_image((*game)->mlx, (*game)->exit_texture);
	if (!(*game)->exit)
		errors_controller("Erreur d'allocations MLX\n", *map);
	(*game)->wall_texture = mlx_load_png("./assets/wall.png");
	if (!(*game)->wall_texture)
		errors_controller("Erreur d'allocations mémoires\n", *map);
	(*game)->wall = mlx_texture_to_image((*game)->mlx, (*game)->wall_texture);
	if (!(*game)->wall)
		errors_controller("Erreur d'allocations MLX\n", *map);
}

void	init_game(t_game *game, t_map_info *map)
{
	(*game).map = map;
	(*game).direction = 0;
	(*game).mlx = mlx_init((*map).x * 128, (*map).y * 128, "so_long", true);
	if (!(*game).mlx)
		errors_controller("Erreur d'allocations mémoires\n", map);
	(*game).player_texture = mlx_load_png("./assets/player.png");
	if (!(*game).player_texture)
		errors_controller("Erreur d'allocations mémoires\n", map);
	(*game).player = mlx_texture_to_image((*game).mlx, (*game).player_texture);
	if (!(*game).player)
		errors_controller("Erreur d'allocations MLX\n", map);
	(*game).background_texture = mlx_load_png("./assets/background.png");
	if (!(*game).background_texture)
		errors_controller("Erreur d'allocations mémoires\n", map);
	(*game).background = mlx_texture_to_image((*game).mlx,
			(*game).background_texture);
	if (!(*game).background)
		errors_controller("Erreur d'allocations MLX\n", map);
	init_draw(&game, &map);
}

void	draw_map(t_game *game, t_map_info *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < (*map).y)
	{
		x = 0;
		while (x < (*map).x)
		{
			if ((*map).map[y][x] == '0' || (*map).map[y][x] == 'P')
			{
				if (mlx_image_to_window((*game).mlx, (*game).background, x * 128,
						y * 128) < 0)
					errors_controller("Erreur lors de l'affichage des images\n",
						map);
			}
			else if ((*map).map[y][x] == '1')
			{
				if (mlx_image_to_window((*game).mlx, (*game).wall, x * 128, y
						* 128) < 0)
					errors_controller("Erreur lors de l'affichage des images\n",
						map);
			}
			else if ((*map).map[y][x] == 'C')
			{
				if (mlx_image_to_window((*game).mlx, (*game).collectible, x
						* 128, y * 128) < 0)
					errors_controller("Erreur lors de l'affichage des images\n",
						map);
			}
			else if ((*map).map[y][x] == 'E')
			{
				if (mlx_image_to_window((*game).mlx, (*game).exit, x * 128, y
						* 128) < 0)
					errors_controller("Erreur lors de l'affichage des images\n",
						map);
				(*game).x_e = x;
				(*game).y_e = y;
			}
			x++;
		}
		y++;
	}
}

void	spawn_player(t_game *game, t_map_info *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < (*map).y)
	{
		x = 0;
		while (x < (*map).x)
		{
			if ((*map).map[y][x] == 'P')
			{
				if (mlx_image_to_window((*game).mlx, (*game).player, x * 128, y
						* 128) < 0)
					errors_controller("Erreur lors de l'affichage des images\n",
						map);
			}
			x++;
		}
		y++;
	}
}

void	resize_game(t_game *game, t_map_info *map)
{
	if (mlx_resize_image((*game).background, 128, 128) == 0)
		errors_controller("Erreur lors du resize des images\n", map);
	if (mlx_resize_image((*game).player, 128, 128) == 0)
		errors_controller("Erreur lors du resize des images\n", map);
	if (mlx_resize_image((*game).collectible, 128, 128) == 0)
		errors_controller("Erreur lors du resize des images\n", map);
	if (mlx_resize_image((*game).wall, 128, 128) == 0)
		errors_controller("Erreur lors du resize des images\n", map);
	if (mlx_resize_image((*game).exit, 128, 128) == 0)
		errors_controller("Erreur lors du resize des images\n", map);
}

void	react_player(t_game *game, t_map_info *map)
{
	(*game).player_texture = mlx_load_png("./assets/player.png");
	if (!(*game).player_texture)
		errors_controller("Erreur d'allocations mémoires\n", map);
	(*game).player = mlx_texture_to_image((*game).mlx, (*game).player_texture);
	if (!(*game).player)
		errors_controller("Erreur d'allocations MLX\n", map);
	if (mlx_resize_image((*game).player, 128, 128) == 0)
		errors_controller("Erreur lors du resize des images\n", map);
}

int	pos(char c, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y <= (*game).map->y)
	{
		x = 0;
		while ((*game).map->map[y][x])
		{
			if ((*game).map->map[y][x] == 'P')
			{
				if (c == 'x')
					return (x);
				if (c == 'y')
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	swap_chars(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	movement(t_game *game, int nx, int ny)
{
	int	x;
	int	y;

	x = pos('x', game);
	y = pos('y', game);
	if ((*game).map->map[y + ny][x + nx] == 'C')
	{
		if (mlx_image_to_window((*game).mlx, (*game).background, (x + nx) * 128,
				(y + ny) * 128) < 0)
			errors_controller("Erreur lors de l'affichage des images\n",
				(*game).map);
		(*game).map->map[y + ny][x + nx] = '0';
		(*game).map->collectible_count--;
	}
	if ((y + ny) == (*game).y_e && (x + nx) == (*game).x_e && (*game).map->collectible_count == 0)
		mlx_close_window((*game).mlx);
	if ((*game).map->map[y + ny][x + nx] != '1')
	{
		swap_chars(&(*game).map->map[y][x], &(*game).map->map[y + ny][x + nx]);
		mlx_delete_image((*game).mlx, (*game).player);
		react_player(game, (*game).map);
		spawn_player(game, (*game).map);
	}
}

void	hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		(*game).direction = 1;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		(*game).direction = 3;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		(*game).direction = 4;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		(*game).direction = 0;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window((*game).mlx);
}

void	delete_all_images(t_game *game)
{
	mlx_delete_texture((*game).background_texture);
	mlx_delete_image((*game).mlx, (*game).background);
	mlx_delete_texture((*game).player_texture);
	mlx_delete_image((*game).mlx, (*game).player);
	mlx_delete_texture((*game).wall_texture);
	mlx_delete_image((*game).mlx, (*game).wall);
	mlx_delete_texture((*game).exit_texture);
	mlx_delete_image((*game).mlx, (*game).exit);
	mlx_delete_texture((*game).collectible_texture);
	mlx_delete_image((*game).mlx, (*game).collectible);
}

void	delay_hook(int s)
{
	int	a;
	int b;

	a = 0;
	while (a < s)
	{
		b = 0;
		while (b < 10000)
			b++;
		a++;
	}
}

void	hook_mov(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if ((*game).direction == 0)
		movement(game, 1, 0);
	else if ((*game).direction == 1)
		movement(game, 0, -1);
	else if ((*game).direction == 3)
		movement(game, 0, 1);
	else if ((*game).direction == 4)
		movement(game, -1, 0);
	delay_hook(3000);
}

int32_t	main(int argc, char **argv)
{
	t_map_info map;
	t_game game;

	map = get_array_map(argv[1]);
	init_game(&game, &map);
	resize_game(&game, &map);
	draw_map(&game, &map);
	spawn_player(&game, &map);
	mlx_key_hook(game.mlx, hook, (void *)&game);
	mlx_loop_hook(game.mlx, hook_mov, (void *)&game);
	mlx_loop(game.mlx);
	delete_all_images(&game);
	mlx_terminate(game.mlx);
	destroy_map(&map);
	return (EXIT_SUCCESS);
}