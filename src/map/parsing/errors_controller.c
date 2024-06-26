/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:38:45 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/14 10:26:52 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors_controller(char *str, t_map_info *map)
{
	ft_printf("%s", str);
	if (map->map != NULL)
		destroy_map(map);
	exit(1);
}
