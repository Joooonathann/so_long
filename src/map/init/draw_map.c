/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:22:50 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/14 07:44:53 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	controller_map(t_game *game, t_map_info *map, int y, int x)
{
	if ((*map).map[y][x] == '1')
	{
		if (mlx_image_to_window((*game).mlx, (*game).wall, x * 128, y
				* 128) < 0)
			errors_controller("Error\n lors de l'affichage des images\n", map);
	}
	else if ((*map).map[y][x] == 'C')
	{
		if (mlx_image_to_window((*game).mlx, (*game).collectible, x * 128, y
				* 128) < 0)
			errors_controller("Error\n lors de l'affichage des images\n", map);
	}
	else if ((*map).map[y][x] == 'E')
	{
		if (mlx_image_to_window((*game).mlx, (*game).exit, x * 128, y
				* 128) < 0)
			errors_controller("Error\n lors de l'affichage des images\n", map);
		(*game).x_e = x;
		(*game).y_e = y;
	}
}

void	draw_map(t_game *game, t_map_info *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < (*map).y)
	{
		x = 0;
		while (x < (*map).x)
		{
			if ((*map).map[y][x] == '0' || (*map).map[y][x] == 'P')
			{
				if (mlx_image_to_window((*game).mlx, (*game).background, x
						* 128, y * 128) < 0)
					errors_controller("Error\n lors de l'affichage des images\n",
						map);
			}
			controller_map(game, map, y, x);
			x++;
		}
		y++;
	}
}
