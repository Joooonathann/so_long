#include "so_long.h"

static int    ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (1);
		str++;
	}
	if (*str == (char)c)
		return (1);

	return (0);
}

int is_valid_object_map(t_map_info *map)
{
	int i;
	int a;

	a = 0;
	i = 0;
	while (i < map->y)
	{
		if (map->map[i][a] == '\0')
		{
			i++;
			a = 0;
			continue;
		}
		if (!ft_strchr("01CEP", map->map[i][a]))
			return (0);
		if (map->map[i][a] == 'E')
			map->exit_count++;
		if (map->map[i][a] == 'P')
			map->spawn_count++;
		if (map->map[i][a] == 'C')
			map->collectible_count++;
		a++;
	}
	if (map->collectible_count <= 0 || map->spawn_count != 1 || map->exit_count != 1)
		return (0);
	return (1);
}