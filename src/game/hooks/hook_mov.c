/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:29:46 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/14 14:28:11 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	delay_hook(int s)
{
	int	a;
	int	b;

	a = 0;
	while (a < s)
	{
		b = 0;
		while (b < 10000)
			b++;
		a++;
	}
}

void	hook_mov(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if ((*game).direction == 0)
		movement(game, 1, 0);
	else if ((*game).direction == 1)
		movement(game, 0, -1);
	else if ((*game).direction == 3)
		movement(game, 0, 1);
	else if ((*game).direction == 4)
		movement(game, -1, 0);
	ft_printf("\33[2K\rDeplacements: %d movements", (*game).movements_count);
	delay_hook(3000);
}
