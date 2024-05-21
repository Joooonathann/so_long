/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   react_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:26:53 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/21 18:29:17 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	react_player(t_game *game)
{
	(*game).player_texture = mlx_load_png("./assets/player.png");
	if (!(*game).player_texture)
		errors_controller_game("Error\n d'allocations mémoires\n", &game);
	(*game).player = mlx_texture_to_image((*game).mlx, (*game).player_texture);
	if (!(*game).player)
		errors_controller_game("Error\n d'allocations MLX\n", &game);
	if (mlx_resize_image((*game).player, 128, 128) == 0)
		errors_controller_game("Error\n lors du resize des images\n", &game);
}
