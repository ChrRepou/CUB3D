/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:20:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/23 20:53:39 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
#include "../../header_files/cub3d_raycasting.h"

static bool	wall_hit(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return (TRUE);
	return (FALSE);
}

static double	get_x_dist(t_player *player, char **map, int map_h, double ray_angle)
{
	t_ray	ray;

	ray.modifier = 0;
	if (fabs(ray_angle) < ANGLE_TOLERANCE || \
		fabs(fabs(ray_angle) - M_PI) < ANGLE_TOLERANCE)
		return (-1);
	if (ray_angle < M_PI)
	{
		ray.hit_y = ceil(player->y_pos);
		ray.direction = 1;
	}
	else
	{
		ray.hit_y = floor(player->y_pos);
		ray.modifier = -1;
		ray.direction = -1;
	}
	ray.hit_x = \
		player->x_pos + (player->y_pos - ray.hit_y) / -tan(ray_angle);
	printf("x axis x and y [%f, %f]\n", ray.hit_x, ray.hit_y);
	while (ray.hit_x >= 0 && ray.hit_x <= map_h) //nott 100% sure about this
	{
		if (wall_hit(map, floor(ray.hit_x), floor(ray.hit_y) + ray.modifier))
			return (fabs((player->y_pos - ray.hit_y) / sin(ray_angle)));
		ray.hit_y = ray.hit_y + ray.direction;
		ray.hit_x = player->x_pos + (player->y_pos - ray.hit_y) / -tan(ray_angle);
	}
	return (-1);
}

static double	get_y_dist(t_player *player, char **map, int map_w, double ray_angle)
{
	t_ray	ray;

	ray.modifier = 0;
	if (fabs(fabs(ray_angle) - M_PI / 2.0) < ANGLE_TOLERANCE || \
		fabs(fabs(ray_angle) - 3.0 * M_PI / 2.0) < ANGLE_TOLERANCE)
		return (-1);
	if (ray_angle > M_PI / 2 && ray_angle < 3 * M_PI / 2)
	{
		ray.hit_x = floor(player->x_pos);
		ray.modifier = -1;
		ray.direction = -1;
	}
	else
	{
		ray.direction = 1;
		ray.hit_x = ceil(player->x_pos);
	}
	ray.hit_y = \
		player->y_pos + (player->x_pos - ray.hit_x) * -tan(ray_angle);
	printf("y axis x and y [%f, %f]\n", ray.hit_x, ray.hit_y);
	while (ray.hit_y >= 0 && ray.hit_y <= map_w)
	{
		if (wall_hit(map, floor(ray.hit_x) + ray.modifier, floor(ray.hit_y)))
			return (fabs((player->x_pos - ray.hit_x) / cos(ray_angle)));
		ray.hit_x = ray.hit_x + ray.direction;
		ray.hit_y = player->y_pos + (player->x_pos - ray.hit_x) * -tan(ray_angle);
	}
	return (-1);
}

double	get_ray_length(t_cub3d *cub3d_data, double ray_angle)
{
	double	x_dist;
	double	y_dist;

	x_dist = \
	get_x_dist(cub3d_data->player, cub3d_data->map, cub3d_data->height, ray_angle);
	y_dist = get_y_dist(cub3d_data->player, cub3d_data->map, cub3d_data->width, ray_angle);
	printf("The distance to x axis is %f\n", x_dist);
	printf("The distance to y axis is %f\n", y_dist);
	if (x_dist != -1 && x_dist < y_dist) //here is a fish
		return (x_dist);
	else
		return (y_dist);
}