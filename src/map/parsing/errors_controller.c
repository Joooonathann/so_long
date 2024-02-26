#include "so_long.h"
#include <stdio.h>

void	errors_controller(char *str, t_map_info *map, t_global game)
{
	printf("%s", str);
	if (map->map != NULL)
		destroy_map(*map);
	if (game.mlx != NULL)
		mlx_terminate(game.mlx);
	exit(1);
}
