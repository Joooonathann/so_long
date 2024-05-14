/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:39:06 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/14 14:17:11 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_info	get_array_map(const char *path_map)
{
	t_map_info	map;

	map = initialize_map();
	if (!is_valid_path(path_map))
		errors_controller("Error\nLe fichier n'est pas valide.\n", &map);
	if (!get_size_map(path_map, &map))
		errors_controller("Error\nLa map n'est pas au normes.\n", &map);
	if (map.x > 40 || map.y > 16)
		errors_controller("Error\nLa map est trop grande.\n", &map);
	if (!set_malloc_map(&map))
		errors_controller("Error\nL'allocation de mémoire a échouée.\n", &map);
	set_object_map(path_map, &map);
	if (map.x == map.y)
		errors_controller("Error\nLa map n'est pas rectangle.\n", &map);
	if (!wall_surround_map(&map))
		errors_controller("Error\nLa map n'est pas entouré de mur.\n", &map);
	if (!is_valid_object_map(&map))
		errors_controller("Error\nLa map contient des objets invalide.\n", &map);
	if (!flood_fill_map(map))
		errors_controller("Error\nLe flood fill n'a pas pus aboutir.\n", &map);
	return (map);
}
