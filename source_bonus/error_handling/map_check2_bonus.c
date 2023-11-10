/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:55:29 by crepou            #+#    #+#             */
/*   Updated: 2023/11/10 17:46:26 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files_bonus/cub3d_bonus.h"

int	check_column(t_cub3d *cub3d_info, int x)
{
	int		y;
	char	**map;

	y = 0;
	map = cub3d_info->map;
	while (y < cub3d_info->height)
	{
		if (map[y][x] == '1')
			return (TRUE);
		if (map[y][x] == 32)
			y++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	check_column_reverse(t_cub3d *cub3d_info, int x)
{
	int		y;
	char	**map;

	y = cub3d_info->height - 1;
	map = cub3d_info->map;
	while (y > -1)
	{
		if (map[y][x] == '1')
			return (TRUE);
		if (map[y][x] == 32)
			y--;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	check_top_wall(t_cub3d *cub3d_info)
{
	int		x;
	char	**map;

	x = 0;
	map = cub3d_info->map;
	while (x < cub3d_info->width)
	{
		if (map[0][x] == '0' || map[0][x] == '2' || map[0][x] == '3')
			return (FALSE);
		else if (map[0][x] == 32)
			if (!check_column(cub3d_info, x))
				return (FALSE);
		x++;
	}
	return (TRUE);
}

int	check_bottom_wall(t_cub3d *cub3d_info)
{
	int		x;
	char	**map;
	int		y;

	x = 0;
	map = cub3d_info->map;
	y = cub3d_info->height - 1;
	while (x < cub3d_info->width)
	{
		if (map[y][x] == '0' || map[y][x] == '2' || map[y][x] == '3')
			return (FALSE);
		else if (map[y][x] == 32)
			if (!check_column_reverse(cub3d_info, x))
				return (FALSE);
		x++;
	}
	return (TRUE);
}
