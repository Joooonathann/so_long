/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:31:00 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/21 18:22:42 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	t_map_info	map;
	t_game		game;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long <map>\n");
		exit(1);
	}
	map = get_array_map(argv[1]);
	init_game(&game, &map);
	resize_game(&game);
	draw_map(&game, &map);
	spawn_player(&game, &map);
	mlx_key_hook(game.mlx, hook, (void *)&game);
	mlx_loop_hook(game.mlx, hook_mov, (void *)&game);
	mlx_loop(game.mlx);
	delete_all_images(&game);
	mlx_terminate(game.mlx);
	destroy_map(&map);
	return (EXIT_SUCCESS);
}
