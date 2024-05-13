/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_malloc_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:39:27 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/13 10:39:28 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_malloc_map(t_map_info *map)
{
	int	i;

	i = 0;
	map->map = (char **)malloc(sizeof(char *) * map->y);
	if (!map->map)
		return (0);
	while (i < map->y)
	{
		map->map[i] = malloc(sizeof(char) * (map->x + 1));
		if (!map->map[i])
		{
			destroy_map(map);
			return (0);
		}
		i++;
	}
	return (1);
}
