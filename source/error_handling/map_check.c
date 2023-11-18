/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:31 by crepou            #+#    #+#             */
/*   Updated: 2023/11/18 15:40:38 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

int	check_row(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == '1')
			return (TRUE);
		if (line[x] == 32)
			x++;
		else
			return (FALSE);
	}
	return (FALSE);
}

int	check_row_reverse(char *line, int width)
{
	int	x;

	x = width;
	while (x > -1)
	{
		if (line[x] == '1')
			return (TRUE);
		if (line[x] == 32)
			x--;
		else
			return (FALSE);
	}
	return (FALSE);
}

int	check_left_wall(t_cub3d *cub3d_info)
{
	int		y;
	char	**map;

	y = 0;
	map = cub3d_info->map;
	while (y < cub3d_info->height)
	{
		if (map[y][0] == '0')
			return (FALSE);
		else if (map[y][0] == 32)
			if (!check_row(map[y]))
				return (FALSE);
		y++;
	}
	return (TRUE);
}

int	check_right_wall(t_cub3d *cub3d_info)
{
	int		y;
	char	**map;
	int		x;

	y = 0;
	map = cub3d_info->map;
	x = cub3d_info->width - 1;
	while (y < cub3d_info->height)
	{
		if (map[y][x] == '0')
			return (FALSE);
		else if (map[y][x] == 32)
			if (!check_row_reverse(map[y], x))
				return (FALSE);
		y++;
	}
	return (TRUE);
}

int	map_is_valid(t_cub3d *cub3d_info)
{
	if (!has_one_player(cub3d_info))
		return (FALSE);
	if (!check_left_wall(cub3d_info) || !check_right_wall(cub3d_info) \
		|| !check_top_wall(cub3d_info) || !check_bottom_wall(cub3d_info))
		return (print("Error!\nThe map is not valid!\n"), FALSE);
	if (!player_can_move(cub3d_info))
		return (FALSE);
	return (TRUE);
}
