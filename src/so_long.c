#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	t_map_info map;

	map = get_array_map(argv[1]);

	destroy_map(&map);

	return (EXIT_SUCCESS);
}