/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:55:45 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/08 21:58:04 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
#include "../../header_files/cub3d_raycasting.h"

/*returns TRUE when ray has intersected a wall*/
bool	is_wall_hit(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return (TRUE);
	return (FALSE);
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
