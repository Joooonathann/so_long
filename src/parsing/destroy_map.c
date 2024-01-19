#include "so_long.h"

void    destroy_map(t_map_info map)
{
	int i;

	i = 0;
	while (i < map.y)
		free(map.map[i++]);
	free(map.map);
}