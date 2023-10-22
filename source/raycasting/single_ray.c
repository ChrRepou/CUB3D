/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:20:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/22 21:41:28 by tmarts           ###   ########.fr       */
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

static double	get_x_distance(t_player *player, char **map, double ray_angle)
{
	t_ray	ray;

	ray.rad = ray_angle * (M_PI / 180);
	ray.modifier = 0;
	if (ray_angle == 0 || ray_angle == 180)
		return (-1);
	if (ray_angle < 180)
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
		player->x_pos + (player->y_pos - ray.hit_y) / -tan(ray.rad);
	printf("x axis x and y [%f, %f]\n", ray.hit_x, ray.hit_y);
	while (ray.hit_x >= 1 && !wall_hit(map, floor(ray.hit_x), floor(ray.hit_y) + ray.modifier))
	{
		ray.hit_y = ray.hit_y + ray.direction;
		ray.hit_x = player->x_pos + (player->y_pos - ray.hit_y) / -tan(ray.rad);
	}
	return (fabs((player->y_pos - ray.hit_y) / sin(ray.rad)));
}

static double	get_y_distance(t_player *player, char **map, double ray_angle)
{
	t_ray	ray;

	ray.rad = ray_angle * (M_PI / 180);
	ray.modifier = 0;
	if (ray_angle == 270 || ray_angle == 90)
		return (-1);
	if (ray_angle > 90 && ray_angle < 270)
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
		player->y_pos + (player->x_pos - ray.hit_x) * -tan(ray.rad);
	printf("y axis x and y [%f, %f]\n", ray.hit_x, ray.hit_y);
	while (ray.hit_y >= 1 && !wall_hit(map, floor(ray.hit_x) + ray.modifier, floor(ray.hit_y)))
	{
		ray.hit_x = ray.hit_x + ray.direction;
		ray.hit_y = player->y_pos + (player->x_pos - ray.hit_x) * -tan(ray.rad);
	}
	return (fabs((player->x_pos - ray.hit_x) / cos(ray.rad)));
}

double	get_ray_length(t_cub3d *cub3d_data, double ray_angle)
{
	double	x_dist;
	double	y_dist;

	x_dist = get_x_distance(cub3d_data->player, cub3d_data->map, ray_angle);
	y_dist = get_y_distance(cub3d_data->player, cub3d_data->map, ray_angle);
	printf("The distance to x axis is %f\n", x_dist);
	printf("The distance to y axis is %f\n", y_dist);
	if (x_dist != -1 && x_dist < y_dist) //here is a fish
		return (x_dist);
	else
		return (y_dist);
}