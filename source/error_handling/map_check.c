/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:31 by crepou            #+#    #+#             */
/*   Updated: 2023/10/03 20:08:57 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

int	check_row(int *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == 1)
			return (TRUE);
		if (line[x] == -1)
			x++;
		else
			return (FALSE);
	}
	return (FALSE);
}

int	check_left_wall(t_cub3d *cub3d_info)
{
	int	y;
	int	**map;

	y = 0;
	map = cub3d_info->map;
	while (y < cub3d_info->height)
	{
		if (map[y][0] == 0)
			return (FALSE);
		else if (map[y][0] == -1)
			if (!check_row(map[y]))
				return (FALSE);
		y++;
	}
	return (TRUE);
}

int	map_is_valid(t_cub3d *cub3d_info)
{
	if (!check_left_wall(cub3d_info))
		return (printf("Error!\nThe map is not valid!\n"), FALSE);
	return (TRUE);
}
