/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_all_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:31:17 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/14 14:32:31 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_all_images(t_game *game)
{
	if ((*game).background_texture)
		mlx_delete_texture((*game).background_texture);
	if ((*game).background)
		mlx_delete_image((*game).mlx, (*game).background);
	if ((*game).player_texture)
		mlx_delete_texture((*game).player_texture);
	if ((*game).player)
		mlx_delete_image((*game).mlx, (*game).player);
	if ((*game).wall_texture)
		mlx_delete_texture((*game).wall_texture);
	if ((*game).wall)
		mlx_delete_image((*game).mlx, (*game).wall);
	if ((*game).exit_texture)
		mlx_delete_texture((*game).exit_texture);
	if ((*game).exit)
		mlx_delete_image((*game).mlx, (*game).exit);
	if ((*game).collectible_texture)
		mlx_delete_texture((*game).collectible_texture);
	if ((*game).collectible)
		mlx_delete_image((*game).mlx, (*game).collectible);
}
