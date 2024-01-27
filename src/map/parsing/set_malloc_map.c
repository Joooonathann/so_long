#include "so_long.h"

int	set_malloc_map(t_map_info *map)
{
	int	i;

	i = 0;
	map->map = (char **)malloc(sizeof(char *) * map->y);
	if (!map->map)
		return (0);
	while (i < map->y)
	{
		map->map[i] = malloc(sizeof(char) * (map->x + 1));
		if (!map->map[i])
		{
			destroy_map(*map);
			return (0);
		}
		i++;
	}
	return (1);
}
