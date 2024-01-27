#include "so_long.h"

int	wall_surround_map(t_map_info *map)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (a < map->y)
	{
		if (map->map[a][i] == '\0')
		{
			a++;
			i = 0;
		}
		else if ((a == 0 || a == map->y - 1) && map->map[a][i] != '1')
			return (0);
		else if ((i == 0 || i == map->x - 1) && map->map[a][i] != '1')
			return (0);
		i++;
		if (i == map->x)
		{
			i = 0;
			a++;
		}
	}
	return (1);
}
