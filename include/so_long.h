#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"

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

typedef struct texture_info
{
	int	line_x;
	int	line_y;
	int	width;
	int	height;
	int	start_x;
	int	start_y;
}	t_texture_info;


t_map_info	get_array_map(const char *path_map);
void        destroy_map(t_map_info map);
int         get_size_map(const char *path_map, t_map_info *map);
t_map_info	initialize_map(void);
int         is_valid_object_map(t_map_info *map);
int         set_malloc_map(t_map_info *map);
void        set_object_map(const char *path_map, t_map_info *map);
int         wall_surround_map(t_map_info *map);
int         flood_fill_map(t_map_info map);
int         is_valid_path(const char *path_map);
void    errors_controller(int error_code, t_map_info *map);
int  	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void    create_game(void);

#endif