/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:39:19 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/13 10:39:20 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_info	initialize_map(void)
{
	t_map_info	map;

	map.x = 0;
	map.y = 1;
	map.map = NULL;
	map.is_valid = 1;
	map.is_error = 0;
	map.exit_count = 0;
	map.spawn_count = 0;
	map.collectible_count = 0;
	return (map);
}
