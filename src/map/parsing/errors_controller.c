#include "so_long.h"

void	errors_controller(char *str, t_map_info *map)
{
	ft_printf("%s", str);
	if (map->map != NULL)
		destroy_map(map);
	exit(1);
}
