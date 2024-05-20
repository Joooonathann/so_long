/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:21:16 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/20 08:48:57 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_clean(t_game *game, char *str)
{
	ft_printf("%s", str);
	if ((*game).map)
		destroy_map((*game).map);
	if ((*game).mlx)
		mlx_terminate((*game).mlx);
	exit(1);
}

static void	init_draw_second(t_game **game)
{
	(*game)->exit = mlx_texture_to_image((*game)->mlx, (*game)->exit_texture);
	if (!(*game)->exit)
		exit_clean(*game, "Erreur d'allocations MLX\n");
	(*game)->wall_texture = mlx_load_png("./assets/wall.png");
	if (!(*game)->wall_texture)
		exit_clean(*game, "Erreur d'allocations mémoires\n");
	(*game)->wall = mlx_texture_to_image((*game)->mlx, (*game)->wall_texture);
	if (!(*game)->wall)
		exit_clean(*game, "Erreur d'allocations MLX\n");
}

static void	init_draw(t_game **game)
{
	(*game)->collectible_texture = mlx_load_png("./assets/collectible.png");
	if (!(*game)->collectible_texture)
		exit_clean(*game, "Erreur d'allocations mémoires\n");
	(*game)->collectible = mlx_texture_to_image((*game)->mlx,
			(*game)->collectible_texture);
	if (!(*game)->collectible)
		exit_clean(*game, "Erreur d'allocations MLX\n");
	(*game)->exit_texture = mlx_load_png("./assets/exit.png");
	if (!(*game)->exit_texture)
		exit_clean(*game, "Erreur d'allocations mémoires\n");
	init_draw_second(game);
}

static void	init_second(t_game **game)
{
	(*game)->player = mlx_texture_to_image((*game)->mlx,
			(*game)->player_texture);
	if (!(*game)->player)
		exit_clean(*game, "Erreur d'allocations MLX\n");
	(*game)->background_texture = mlx_load_png("./assets/background.png");
	if (!(*game)->background_texture)
		exit_clean(*game, "Erreur d'allocations mémoires\n");
	(*game)->background = mlx_texture_to_image((*game)->mlx,
			(*game)->background_texture);
	if (!(*game)->background)
		exit_clean(*game, "Erreur d'allocations MLX\n");
}

void	init_game(t_game *game, t_map_info *map)
{
	(*game).movements_count = 0;
	(*game).map = map;
	(*game).direction = -1;
	(*game).mlx = mlx_init((*map).x * 128, (*map).y * 128, "so_long", true);
	if (!(*game).mlx)
		exit_clean(game, "Erreur d'allocations MLX\n");
	(*game).player_texture = mlx_load_png("./assets/player.png");
	if (!(*game).player_texture)
		exit_clean(game, "Erreur d'allocations mémoires\n");
	init_second(&game);
	init_draw(&game);
}
