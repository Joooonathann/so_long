/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:24:39 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/23 10:00:49 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spawn_player(t_game *game, t_map_info *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < (*map).y)
	{
		x = 0;
		while (x < (*map).x)
		{
			if ((*map).map[y][x] == 'P')
			{
				if (mlx_image_to_window((*game).mlx, (*game).player, x * 128, y
						* 128) < 0)
					errors_controller_game(
						"Error\n lors de l'affichage des images\n",
						&game);
			}
			x++;
		}
		y++;
	}
}
