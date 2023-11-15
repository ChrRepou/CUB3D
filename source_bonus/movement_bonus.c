/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:02:03 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/15 15:22:25 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files_bonus/cub3d_bonus.h"
#include "../header_files_bonus/cub3d_minimap_bonus.h"

/*returns true, when player position has reached the wall*/
bool	is_wall(char **map, double x, double y)
{
	if (map[(int)(y + 0.2)][(int)(x + 0.2)] == '1' || \
		map[(int)(y - 0.2)][(int)(x - 0.2)] == '1' || \
		map[(int)(y + 0.2)][(int)(x - 0.2)] == '1' || \
		map[(int)(y - 0.2)][(int)(x + 0.2)] == '1' || \
		map[(int)(y + 0.2)][(int)(x + 0.2)] == '2' || \
		map[(int)(y - 0.2)][(int)(x - 0.2)] == '2' || \
		map[(int)(y + 0.2)][(int)(x - 0.2)] == '2' || \
		map[(int)(y - 0.2)][(int)(x + 0.2)] == '2')
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
