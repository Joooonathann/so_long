/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:28:32 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/21 18:29:09 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(t_game *game, int nx, int ny)
{
	int	x;
	int	y;

	x = pos('x', game);
	y = pos('y', game);
	if ((*game).map->map[y + ny][x + nx] == 'C')
	{
		if (mlx_image_to_window((*game).mlx, (*game).background, (x + nx) * 128,
				(y + ny) * 128) < 0)
			errors_controller_game("Erreur lors de l'affichage des images\n",
				&game);
		(*game).map->map[y + ny][x + nx] = '0';
		(*game).map->collectible_count--;
	}
	if ((y + ny) == (*game).y_e && (x + nx) == (*game).x_e
		&& (*game).map->collectible_count == 0)
		mlx_close_window((*game).mlx);
	if ((*game).map->map[y + ny][x + nx] != '1')
	{
		swap_chars(&(*game).map->map[y][x], &(*game).map->map[y + ny][x + nx]);
		mlx_delete_image((*game).mlx, (*game).player);
		react_player(game);
		spawn_player(game, (*game).map);
		(*game).movements_count++;
	}
}
