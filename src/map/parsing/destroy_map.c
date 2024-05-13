/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:37:53 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/13 10:38:00 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(t_map_info *map)
{
	int	i;

	i = 0;
	while (i < map->y)
		free(map->map[i++]);
	free(map->map);
}
