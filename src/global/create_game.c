#include "so_long.h"

void    create_game(void)
{
    t_map_info  map;
	t_global	game;
	mlx_t		*mlx;

	map = get_array_map("./maps/map.ber");
	mlx = mlx_init(64 * map.x, 64 * map.y, "so_long", true);
	game = init_global(&mlx, &map);
    display_map(&game);
	mlx_loop(mlx);
	destroy_map(map);
	mlx_terminate(mlx);
}