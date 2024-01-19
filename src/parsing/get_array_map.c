#include "so_long.h"

t_map_info  get_array_map(const char *path_map)
{
	t_map_info  map;

	map = initialize_map();
	if (!is_valid_path(path_map))
		errors_controller(1);
	if (!get_size_map(path_map, &map))
		errors_controller(2);
	if (!set_malloc_map(&map))
		errors_controller(3);
	set_object_map(path_map, &map);
	if (map.x == map.y)
		errors_controller(4);
	if (!wall_surround_map(&map))
		errors_controller(5);
	if (!is_valid_object_map(&map))
		errors_controller(6);
	if (!flood_fill_map(map))
		errors_controller(7);
	return (map);
}