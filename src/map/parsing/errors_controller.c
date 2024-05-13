/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:38:45 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/13 10:38:46 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	errors_controller(char *str, t_map_info *map)
{
	printf("%s", str);
	if (map->map != NULL)
		destroy_map(map);
	exit(1);
}
