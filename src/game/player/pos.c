/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:27:11 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/13 10:27:18 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pos(char c, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y <= (*game).map->y)
	{
		x = 0;
		while ((*game).map->map[y][x])
		{
			if ((*game).map->map[y][x] == 'P')
			{
				if (c == 'x')
					return (x);
				if (c == 'y')
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
