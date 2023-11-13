/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:55:45 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/13 15:53:23 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files_bonus/cub3d_bonus.h"
#include "../../header_files_bonus/cub3d_raycasting_bonus.h"

/*returns TRUE when ray has intersected a wall*/
bool	is_wall_hit(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '2' || map[y][x] == '3')
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

/*returns the 0 to full circle angle (in radians) of the ray*/
double	get_true_angle(double player_angle, double ray_angle)
{
	double	temp_angle;

	temp_angle = player_angle + ray_angle;
	if (temp_angle >= 2 * M_PI)
		return (temp_angle - (2 * M_PI));
	else if (temp_angle < 0)
		return (temp_angle + (2 * M_PI));
	return (temp_angle);
}
