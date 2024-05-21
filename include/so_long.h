/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:40:24 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/21 18:29:28 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../printf/include/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map_info
{
	int				x;
	int				y;
	char			**map;
	int				is_valid;
	int				is_error;
	int				exit_count;
	int				spawn_count;
	int				collectible_count;
}					t_map_info;

typedef struct s_game
{
	int				direction;
	int				x_e;
	int				y_e;
	int				movements_count;
	mlx_t			*mlx;
	mlx_texture_t	*player_texture;
	mlx_image_t		*player;
	mlx_texture_t	*background_texture;
	mlx_image_t		*background;
	mlx_texture_t	*collectible_texture;
	mlx_image_t		*collectible;
	mlx_texture_t	*exit_texture;
	mlx_image_t		*exit;
	mlx_texture_t	*wall_texture;
	mlx_image_t		*wall;
	t_map_info		*map;
}					t_game;

t_map_info			get_array_map(const char *path_map);
void				destroy_map(t_map_info *map);
int					get_size_map(const char *path_map, t_map_info *map);
t_map_info			initialize_map(void);
int					is_valid_object_map(t_map_info *map);
int					set_malloc_map(t_map_info *map);
void				set_object_map(const char *path_map, t_map_info *map);
int					wall_surround_map(t_map_info *map);
int					flood_fill_map(t_map_info map);
int					is_valid_path(const char *path_map);
void				errors_controller(char *str, t_map_info *map);
int					ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
void				init_game(t_game *game, t_map_info *map);
void				draw_map(t_game *game, t_map_info *map);
void				spawn_player(t_game *game, t_map_info *map);
void				swap_chars(char *a, char *b);
void				hook_mov(void *param);
void				hook(mlx_key_data_t keydata, void *param);
void				delete_all_images(t_game *game);
void				movement(t_game *game, int nx, int ny);
int					pos(char c, t_game *game);
void				react_player(t_game *game);
void				resize_game(t_game *game);
void				errors_controller_game(char *str, t_game **game);

#endif