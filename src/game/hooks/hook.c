/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:28:55 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/14 14:24:02 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		(*game).direction = 1;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		(*game).direction = 3;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		(*game).direction = 4;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		(*game).direction = 0;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window((*game).mlx);
}
