/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:53:44 by crepou            #+#    #+#             */
/*   Updated: 2023/10/22 19:36:48 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

int	has_one_player(t_cub3d *cub3d_info)
{
	int		x;
	int		y;
	int		players;
	char	**map;

	y = 0;
	players = 0;
	map = cub3d_info->map;
	while (y < cub3d_info->height)
	{
		x = 0;
		while (x < cub3d_info->width)
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' \
				|| map[y][x] == 'E' || map[y][x] == 'W')
				players++;
			x++;
		}
		y++;
	}
	if (players == 1)
		return (TRUE);
	else if (players < 1)
		return (print("Error! You don't have players!\n"), FALSE);
	return (print("Error! You have more than one players!\n"), FALSE);
}

int	player_can_move(t_cub3d *cub3d_info)
{
	int		x;
	int		y;
	char	**map;
	int		walls;

	x = cub3d_info->player->x_pos;
	y = cub3d_info->player->y_pos;
	map = cub3d_info->map;
	walls = 0;
	if ((x - 1) > -1 && map[y][x - 1] == '1')
		walls++;
	if ((x + 1) < cub3d_info->width && map[y][x - 1] == '1')
		walls++;
	if ((y - 1) > -1 && map[y - 1][x] == '1')
		walls++;
	if ((y + 1) < cub3d_info->height && map[y + 1][x] == '1')
		walls++;
	if (walls == 4)
		return (print("Error! Your player can't move!\n"), FALSE);
	return (TRUE);
}
