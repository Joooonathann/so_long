/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:21:16 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/13 10:45:09 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_draw(t_game **game, t_map_info **map)
{
	(*game)->collectible_texture = mlx_load_png("./assets/collectible.png");
	if (!(*game)->collectible_texture)
		errors_controller("Error\n d'allocations mémoires\n", *map);
	(*game)->collectible = mlx_texture_to_image((*game)->mlx,
			(*game)->collectible_texture);
	if (!(*game)->collectible)
		errors_controller("Error\n d'allocations MLX\n", *map);
	(*game)->exit_texture = mlx_load_png("./assets/exit.png");
	if (!(*game)->exit_texture)
		errors_controller("Error\n d'allocations mémoires\n", *map);
	(*game)->exit = mlx_texture_to_image((*game)->mlx, (*game)->exit_texture);
	if (!(*game)->exit)
		errors_controller("Error\n d'allocations MLX\n", *map);
	(*game)->wall_texture = mlx_load_png("./assets/wall.png");
	if (!(*game)->wall_texture)
		errors_controller("Error\n d'allocations mémoires\n", *map);
	(*game)->wall = mlx_texture_to_image((*game)->mlx, (*game)->wall_texture);
	if (!(*game)->wall)
		errors_controller("Error\n d'allocations MLX\n", *map);
}

void	init_game(t_game *game, t_map_info *map)
{
	(*game).map = map;
	(*game).direction = 0;
	(*game).mlx = mlx_init((*map).x * 128, (*map).y * 128, "so_long", true);
	if (!(*game).mlx)
		errors_controller("Error\n d'allocations mémoires\n", map);
	(*game).player_texture = mlx_load_png("./assets/player.png");
	if (!(*game).player_texture)
		errors_controller("Error\n d'allocations mémoires\n", map);
	(*game).player = mlx_texture_to_image((*game).mlx, (*game).player_texture);
	if (!(*game).player)
		errors_controller("Error\n d'allocations MLX\n", map);
	(*game).background_texture = mlx_load_png("./assets/background.png");
	if (!(*game).background_texture)
		errors_controller("Error\n d'allocations mémoires\n", map);
	(*game).background = mlx_texture_to_image((*game).mlx,
			(*game).background_texture);
	if (!(*game).background)
		errors_controller("Error\n d'allocations MLX\n", map);
	init_draw(&game, &map);
}
