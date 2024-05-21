/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_controller_game.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:19:54 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/21 18:30:28 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors_controller_game(char *str, t_game **game)
{

	ft_printf("%s", str);
	if ((*game)->mlx)
		mlx_terminate((*game)->mlx);
	if ((*game)->map)
		destroy_map((*game)->map);
	exit(1);
}