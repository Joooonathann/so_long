/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   react_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:26:53 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/13 10:44:53 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	react_player(t_game *game, t_map_info *map)
{
	(*game).player_texture = mlx_load_png("./assets/player.png");
	if (!(*game).player_texture)
		errors_controller("Error\n d'allocations mémoires\n", map);
	(*game).player = mlx_texture_to_image((*game).mlx, (*game).player_texture);
	if (!(*game).player)
		errors_controller("Error\n d'allocations MLX\n", map);
	if (mlx_resize_image((*game).player, 128, 128) == 0)
		errors_controller("Error\n lors du resize des images\n", map);
}
