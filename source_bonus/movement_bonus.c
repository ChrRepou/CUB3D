/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:02:03 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/17 15:15:09 by tmarts           ###   ########.fr       */
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
	double	new_x;

	dx = cos(player->angle);
	dy = sin(player->angle);
	new_x = x + dx * MOVE_SPEED;
	if (dx != 0 && !is_wall(map, new_x, y))
		player->x_pos = new_x;
	y += dy * MOVE_SPEED;
	if (dy != 0 && !is_wall(map, x, y))
		player->y_pos = y;
}

void	move_backward(t_player *player, char **map, double x, double y)
{
	double	dx;
	double	dy;
	double	new_x;

	dx = cos(player->angle);
	dy = sin(player->angle);
	new_x = x - dx * MOVE_SPEED;
	if (dx != 0 && !is_wall(map, new_x, y))
		player->x_pos = new_x;
	y -= dy * MOVE_SPEED;
	if (dy != 0 && !is_wall(map, x, y))
		player->y_pos = y;
}

void	move_left(t_player *player, char **map, double x, double y)
{
	double	dx;
	double	dy;
	double	new_x;

	dx = cos(player->angle);
	dy = sin(player->angle);
	new_x = x + dy * MOVE_SPEED;
	if (dy != 0 && !is_wall(map, new_x, y))
		player->x_pos = new_x;
	y -= dx * MOVE_SPEED;
	if (dx != 0 && !is_wall(map, x, y))
		player->y_pos = y;
}

void	move_right(t_player *player, char **map, double x, double y)
{
	double	dx;
	double	dy;
	double	new_x;

	dx = cos(player->angle);
	dy = sin(player->angle);
	new_x = x - dy * MOVE_SPEED;
	if (dy != 0 && !is_wall(map, new_x, y))
		player->x_pos = new_x;
	y += dx * MOVE_SPEED;
	if (dx != 0 && !is_wall(map, x, y))
		player->y_pos = y;
}
