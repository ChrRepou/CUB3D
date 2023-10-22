/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:06:11 by crepou            #+#    #+#             */
/*   Updated: 2023/10/21 16:24:20 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

int	is_in_edge(int x, int y, t_cub3d *cub3d_info)
{
	int	width;
	int	height;

	width = cub3d_info->width - 1;
	height = cub3d_info->height - 1;
	if (x == 0 || y == 0 || x == width || y == height)
		return (TRUE);
	return (FALSE);
}

int	replace(t_cub3d *cub3d_info, int x, int y)
{
	char	**map;

	map = cub3d_info->map;
	if (is_in_edge(x, y, cub3d_info))
		map[y][x] = '1';
	else
		map[y][x] = '0';
	return (TRUE);
}

int	replace_spaces(t_cub3d *cub3d_info)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = cub3d_info->map;
	while (y < cub3d_info->height)
	{
		x = 0;
		while (x < cub3d_info->width)
		{
			if (map[y][x] == 32)
				replace(cub3d_info, x, y);
			else if (is_player(map[y][x]))
				map[y][x] = '0';
			x++;
		}
		y++;
	}
	return (TRUE);
}
