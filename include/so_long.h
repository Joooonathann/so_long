#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct map_info
{
    int     x;
    int     y;
    char    **map;
    int     is_valid;
    int     is_error;
    int     exit_count;
    int     spawn_count;
    int     collectible_count;
}   t_map_info;

t_map_info  get_array_map(const char *path_map);
void        destroy_map(t_map_info map);
int         get_size_map(const char *path_map, t_map_info *map);
t_map_info  initialize_map();
int         is_valid_object_map(t_map_info *map);
int         set_malloc_map(t_map_info *map);
void        set_object_map(const char *path_map, t_map_info *map);
int         wall_surround_map(t_map_info *map);
int         flood_fill_map(t_map_info map);

#endif