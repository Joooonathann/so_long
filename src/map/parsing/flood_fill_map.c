/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:38:54 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/13 10:39:04 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_info	mapdup(t_map_info map)
{
	t_map_info	result_map;
	int			y;
	int			x;

	result_map = initialize_map();
	result_map.x = map.x;
	result_map.y = map.y;
	if (!set_malloc_map(&result_map))
		return ((result_map.is_error = 1), result_map);
	y = 0;
	while (y < result_map.y)
	{
		x = 0;
		while (map.map[y][x] != '\0')
			result_map.map[y][x++] = map.map[y][x];
		result_map.map[y][x] = '\0';
		y++;
	}
	return (result_map);
}

void	flood_fill(t_map_info *map_tmp, int x, int y)
{
	if (y < 0 || y >= map_tmp->y || x < 0 || x >= map_tmp->x)
		return ;
	if (map_tmp->map[y][x] == '1' || map_tmp->map[y][x] == 'x')
		return ;
	if (map_tmp->map[y][x] == 'E')
		map_tmp->exit_count++;
	if (map_tmp->map[y][x] == 'C')
		map_tmp->collectible_count++;
	map_tmp->map[y][x] = 'x';
	flood_fill(map_tmp, (x - 1), y);
	flood_fill(map_tmp, (x + 1), y);
	flood_fill(map_tmp, x, (y - 1));
	flood_fill(map_tmp, x, (y + 1));
}

int	spawn_info(t_map_info map, int direction)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.y)
	{
		x = 0;
		while (map.map[y][x] != '\0')
		{
			if (map.map[y][x] == 'P')
			{
				if (direction == 1)
					return (x);
				else if (direction == 2)
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	flood_fill_map(t_map_info map)
{
	t_map_info	map_tmp;

	map_tmp = mapdup(map);
	if (map_tmp.is_error)
	{
		destroy_map(&map_tmp);
		return (0);
	}
	flood_fill(&map_tmp, spawn_info(map_tmp, 1), spawn_info(map_tmp, 2));
	if ((map_tmp.collectible_count != map.collectible_count)
		|| (map_tmp.exit_count != map.exit_count))
	{
		destroy_map(&map_tmp);
		return (0);
	}
	destroy_map(&map_tmp);
	return (1);
}
