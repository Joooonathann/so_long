/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:25:31 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/20 08:45:32 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_clean(t_game *game, char *str)
{
	ft_printf("%s", str);
	if ((*game).map)
		destroy_map((*game).map);
	if ((*game).mlx)
		mlx_terminate((*game).mlx);
	exit(1);
}

void	resize_game(t_game *game)
{
	if (mlx_resize_image((*game).background, 128, 128) == 0)
		exit_clean(game, "Erreur lors du resize des images\n");
	if (mlx_resize_image((*game).player, 128, 128) == 0)
		exit_clean(game, "Erreur lors du resize des images\n");
	if (mlx_resize_image((*game).collectible, 128, 128) == 0)
		exit_clean(game, "Erreur lors du resize des images\n");
	if (mlx_resize_image((*game).wall, 128, 128) == 0)
		exit_clean(game, "Erreur lors du resize des images\n");
	if (mlx_resize_image((*game).exit, 128, 128) == 0)
		exit_clean(game, "Erreur lors du resize des images\n");
}
