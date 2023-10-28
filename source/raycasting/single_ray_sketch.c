/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_ray_sketch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:20:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/28 21:53:00 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
#include "../../header_files/cub3d_raycasting.h"

static int	get_x_intersect(t_cub3d *cub3d, t_pt *pt, double true_angle)
{
	t_ray_utils	ray;

	ray.modifier = 0;
	ray.direction = 1;
	ray.O_pt = cub3d->player;
	if (fabs(true_angle) < ANGLE_TOLERANCE || \
		fabs(fabs(true_angle) - M_PI) < ANGLE_TOLERANCE)
		return (FALSE);
	if (true_angle < M_PI)
		pt->y = ceil(ray.O_pt->y_pos);
	else
	{
		pt->y = floor(ray.O_pt->y_pos);
		ray.modifier = -1;
		ray.direction = -1;
	}
	pt->x = ray.O_pt->x_pos + (ray.O_pt->y_pos - pt->y) / -tan(true_angle);
	while (pt->x >= 0 && pt->x <= cub3d->width - 1 && pt->y <= cub3d->height)
	{
		if (wall_hit(cub3d->map, floor(pt->x), floor(pt->y) + ray.modifier))
			return (TRUE);
		pt->y = pt->y + ray.direction;
		pt->x = ray.O_pt->x_pos + (ray.O_pt->y_pos - pt->y) / -tan(true_angle);
	}
	return (FALSE);
}

static int	get_y_intersect(t_cub3d *cub3d, t_pt *pt, double true_angle)
{
	t_ray_utils	ray;

	ray.modifier = 0;
	ray.direction = 1;
	ray.O_pt = cub3d->player;
	if (fabs(fabs(true_angle) - M_PI / 2.0) < ANGLE_TOLERANCE || \
		fabs(fabs(true_angle) - 3.0 * M_PI / 2.0) < ANGLE_TOLERANCE)
		return (FALSE);
	if (true_angle > M_PI / 2 && true_angle < 3 * M_PI / 2)
	{
		pt->x = floor(ray.O_pt->x_pos);
		ray.modifier = -1;
		ray.direction = -1;
	}
	else
		pt->x = ceil(ray.O_pt->x_pos);
	pt->y = ray.O_pt->y_pos + (ray.O_pt->x_pos - pt->x) * -tan(true_angle);
	while (pt->y >= 0 && pt->y <= cub3d->height - 1 && pt->x <= cub3d->width)
	{
		if (wall_hit(cub3d->map, floor(pt->x) + ray.modifier, floor(pt->y)))
			return (TRUE);
		pt->x = pt->x + ray.direction;
		pt->y = ray.O_pt->y_pos + (ray.O_pt->x_pos - pt->x) * -tan(true_angle);
	}
	return (FALSE);
}

void	find_wall(t_cub3d *cub3d_data, t_ray *ray)
{
	t_pt	x_intersect;
	t_pt	y_intersect;
	int		x_success;
	int		y_success;
	double	x_dist;
	double	y_dist;
	
	// double	true_angle; assume that was calculated beforehand

	// true_angle = get_true_angle(cub3d_data->player->angle, ray_angle);
	x_success = get_x_intersect(cub3d_data, &x_intersect, ray->true_angle);
	y_success = get_y_intersect(cub3d_data, &y_intersect, ray->true_angle);
	if (x_success == TRUE && y_success == TRUE)
	{
		if (x_dist <= y_dist)
			return (get_wall_pixels(cub3d_data->raycaster, x_dist, ray_angle));
		return (get_wall_pixels(cub3d_data->raycaster, y_dist, ray_angle));
	}
	else if (x_dist == -1)
		return (get_wall_pixels(cub3d_data->raycaster, y_dist, ray_angle));
	return (get_wall_pixels(cub3d_data->raycaster, x_dist, ray_angle));
}

int	get_column_data(t_cub3d *cub3d_data, double ray_angle)
{
	t_pt	x_intersect;
	t_pt	y_intersect;
	double	true_angle;

	true_angle = get_true_angle(cub3d_data->player->angle, ray_angle);
	get_x_intersect(cub3d_data, &x_intersect, true_angle);
	get_y_intersect(cub3d_data, &y_intersect, true_angle);
	



	
	x_dist = \
	get_x_dist(cub3d_data->player, cub3d_data->map, cub3d_data->width, cub3d_data->height, true_angle);
	y_dist = \
	get_y_dist(cub3d_data->player, cub3d_data->map, cub3d_data->width, cub3d_data->height, true_angle);
	printf("x-dist: %f, y-dist %f\n", x_dist, y_dist);
	if (x_dist != -1 && y_dist != -1)
	{
		if (x_dist <= y_dist)
			return (get_wall_pixels(cub3d_data->raycaster, x_dist, ray_angle));
		return (get_wall_pixels(cub3d_data->raycaster, y_dist, ray_angle));
	}
	else if (x_dist == -1)
		return (get_wall_pixels(cub3d_data->raycaster, y_dist, ray_angle));
	return (get_wall_pixels(cub3d_data->raycaster, x_dist, ray_angle));
}


// (fabs((player->y_pos - ray.hit_y) / sin(true_angle)));