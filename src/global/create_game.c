#include "so_long.h"

void    create_game(void)
{
    t_map_info  map;

	map = get_array_map("./maps/map.ber");
	mlx_t* mlx = mlx_init(64 * map.x, 64 * map.y, "so_long", true);

    display_map(mlx, map);

	mlx_loop(mlx);
	
	mlx_terminate(mlx);
}