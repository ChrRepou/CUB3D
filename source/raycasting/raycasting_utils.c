/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:55:45 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/18 14:31:20 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
#include "../../header_files/cub3d_raycasting.h"

/*returns TRUE when ray has intersected a wall*/
bool	is_wall_hit(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '2' || map[y][x] == '3')
		return (TRUE);
	return (FALSE);
}

/*returns TRUE when the coordinates are withn the map*/
bool	valid_coords(const t_pt *point, int map_width, int map_height)
{
	if ((int)point->x >= 0 && (int)point->x < map_width && \
	(int)point->y >= 0 && (int)point->y < map_height)
		return (TRUE);
	return (FALSE);
}

/*returns the direction of the wall
based on the angle of the ray and the axis intersection */
t_orientation	get_wall(double angle, char hit_axis)
{
	if (hit_axis == 'x')
	{
		if (angle < M_PI)
			return (S);
		else
			return (N);
	}
	else
	{
		if (angle > M_PI_2 && angle < (3 * M_PI / 2))
			return (W);
		else
			return (E);
	}
}

/*removes fisheye distortion from the distance.
returns corrected value*/
double	remove_distortion(double distance, double angle_offcenter)
{
	return (distance * cos(angle_offcenter));
}
