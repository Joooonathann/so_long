/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:25:31 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/14 13:42:05 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_clean(t_game *game)
{
	delete_all_images(game);
	mlx_terminate((*game).mlx);
}

void	resize_game(t_game *game, t_map_info *map)
{
	if (mlx_resize_image((*game).background, 128, 128) == 0)
	{
		exit_clean(game);
		errors_controller("Error\n lors du resize des images\n", map);
	}
	if (mlx_resize_image((*game).player, 128, 128) == 0)
	{
		exit_clean(game);
		errors_controller("Error\n lors du resize des images\n", map);
	}
	if (mlx_resize_image((*game).collectible, 128, 128) == 0)
	{
		exit_clean(game);
		errors_controller("Error\n lors du resize des images\n", map);
	}
	if (mlx_resize_image((*game).wall, 128, 128) == 0)
	{
		exit_clean(game);
		errors_controller("Error\n lors du resize des images\n", map);
	}
	if (mlx_resize_image((*game).exit, 128, 128) == 0)
	{
		exit_clean(game);
		errors_controller("Error\n lors du resize des images\n", map);
	}
}
