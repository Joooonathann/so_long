/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_controller_game.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:19:54 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/23 10:01:38 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors_controller_game(char *str, t_game **game)
{
	ft_printf("%s", str);
	delete_all_images(*game);
	if ((*game)->mlx)
		mlx_terminate((*game)->mlx);
	if ((*game)->map)
		destroy_map((*game)->map);
	exit(1);
}
