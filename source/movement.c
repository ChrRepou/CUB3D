/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:02:03 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/17 15:19:11 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

/*returns true, when player position has reached the wall*/
bool	is_wall(char **map, double x, double y)
{
	if (map[(int)(y + 0.2)][(int)(x + 0.2)] == '1' || \
		map[(int)(y - 0.2)][(int)(x - 0.2)] == '1' || \
		map[(int)(y + 0.2)][(int)(x - 0.2)] == '1' || \
		map[(int)(y - 0.2)][(int)(x + 0.2)] == '1')
		return (TRUE);
	else
		return (FALSE);
}

void	move_forward(t_player *player, char **map, double x, double y)
{
	double	dx;
	double	dy;

	dx = cos(player->angle);
	dy = sin(player->angle);
	x += dx * MOVE_SPEED;
	y += dy * MOVE_SPEED;
	if (!is_wall(map, x, y))
	{
		player->x_pos = x;
		player->y_pos = y;
	}
}

void	move_backward(t_player *player, char **map, double x, double y)
{
	double	dx;
	double	dy;

	dx = cos(player->angle);
	dy = sin(player->angle);
	x -= dx * MOVE_SPEED;
	y -= dy * MOVE_SPEED;
	if (!is_wall(map, x, y))
	{
		player->x_pos = x;
		player->y_pos = y;
	}
}

void	move_left(t_player *player, char **map, double x, double y)
{
	double	dx;
	double	dy;

	dx = cos(player->angle);
	dy = sin(player->angle);
	x += dy * MOVE_SPEED;
	y -= dx * MOVE_SPEED;
	if (!is_wall(map, x, y))
	{
		player->x_pos = x;
		player->y_pos = y;
	}
}

void	move_right(t_player *player, char **map, double x, double y)
{
	double	dx;
	double	dy;

	dx = cos(player->angle);
	dy = sin(player->angle);
	x -= dy * MOVE_SPEED;
	y += dx * MOVE_SPEED;
	if (!is_wall(map, x, y))
	{
		player->x_pos = x;
		player->y_pos = y;
	}
}
