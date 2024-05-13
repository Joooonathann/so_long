/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_object_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:39:22 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/13 10:41:57 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (1);
		str++;
	}
	if (*str == (char)c)
		return (1);
	return (0);
}

void	add_count(t_map_info *map, int i, int a)
{
	if (map->map[i][a] == 'E')
		map->exit_count++;
	if (map->map[i][a] == 'P')
		map->spawn_count++;
	if (map->map[i][a] == 'C')
		map->collectible_count++;
}

int	is_valid_object_map(t_map_info *map)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (i < map->y)
	{
		if (map->map[i][a] == '\0')
		{
			i++;
			a = 0;
			continue ;
		}
		if (!ft_strchr("01CEP", map->map[i][a]))
			return (0);
		add_count(map, i, a);
		a++;
	}
	if (map->collectible_count <= 0 || map->spawn_count != 1
		|| map->exit_count != 1)
		return (0);
	return (1);
}
