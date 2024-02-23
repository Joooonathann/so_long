#include "so_long.h"
#include <stdio.h>

void	errors_controller(char *str, t_map_info *map)
{
	printf("%s", str);
	if (map->map != NULL)
		destroy_map(*map);
	exit(1);
}
