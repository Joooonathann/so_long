/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:39:25 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/14 13:20:35 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	has_ber_extension(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len >= 4 && ft_strcmp(filename + len - 4, ".ber") == 0)
		return (1);
	else
		return (0);
}

int	is_valid_path(const char *path_map)
{
	int	fd;

	fd = open(path_map, O_RDONLY);
	if ((fd < -1) || (read(fd, 0, 0) == -1))
	{
		close(fd);
		return (0);
	}
	close(fd);
	if (!has_ber_extension(path_map))
	{
		close(fd);
		return (0);
	}
	return (1);
}
