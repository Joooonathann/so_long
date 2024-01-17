#include "so_long.h"

t_map_info  get_array_map(const char *path_map)
{
	t_map_info  map;

	map = initialize_map();
	if (!get_size_map(path_map, &map))
		return ((map.is_error = 1), map);
	if (!set_malloc_map(&map))
		return ((map.is_error = 1), map);
	set_object_map(path_map, &map);
	if (map.x == map.y)
		return ((map.is_valid = 0), map);
	if (!wall_surround_map(&map))
		return ((map.is_valid = 0), map);
	if (!is_valid_object_map(&map))
		return ((map.is_valid = 0), map);
	if (!flood_fill_map(map))
		return ((map.is_valid = 0), map);
	return (map);
}