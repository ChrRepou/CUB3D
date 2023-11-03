/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_ray_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:20:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/03 15:09:15 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
#include "../../header_files/cub3d_raycasting.h"

static int	get_x_intersect(t_cub3d *cub3d, t_pt *pt, double true_angle)
{
	t_ray_utils	ray;

	ray.modifier = 0;
	ray.direction = 1;
	ray.pt_0 = cub3d->player;
	if (fabs(true_angle) < ANGLE_TOLERANCE || \
		fabs(fabs(true_angle) - M_PI) < ANGLE_TOLERANCE)
		return (FALSE);
	if (true_angle < M_PI)
		pt->y = ceil(ray.pt_0->y_pos);
	else
	{
		pt->y = floor(ray.pt_0->y_pos);
		ray.modifier = -1;
		ray.direction = -1;
	}
	pt->x = ray.pt_0->x_pos + (ray.pt_0->y_pos - pt->y) / -tan(true_angle);
	while (pt->x >= 0 && pt->x <= cub3d->width - 1 && pt->y <= cub3d->height)
	{
		if (is_wall_hit(cub3d->map, floor(pt->x), floor(pt->y) + ray.modifier))
			return (TRUE);
		pt->y = pt->y + ray.direction;
		pt->x = ray.pt_0->x_pos + (ray.pt_0->y_pos - pt->y) / -tan(true_angle);
	}
	return (FALSE);
}

static int	get_y_intersect(t_cub3d *cub3d, t_pt *pt, double true_angle)
{
	t_ray_utils	ray;

	ray.modifier = 0;
	ray.direction = 1;
	ray.pt_0 = cub3d->player;
	if (fabs(fabs(true_angle) - M_PI / 2.0) < ANGLE_TOLERANCE || \
		fabs(fabs(true_angle) - 3.0 * M_PI / 2.0) < ANGLE_TOLERANCE)
		return (FALSE);
	if (true_angle > M_PI / 2 && true_angle < 3 * M_PI / 2)
	{
		pt->x = floor(ray.pt_0->x_pos);
		ray.modifier = -1;
		ray.direction = -1;
	}
	else
		pt->x = ceil(ray.pt_0->x_pos);
	pt->y = ray.pt_0->y_pos + (ray.pt_0->x_pos - pt->x) * -tan(true_angle);
	while (pt->y >= 0 && pt->y <= cub3d->height - 1 && pt->x <= cub3d->width)
	{
		if (is_wall_hit(cub3d->map, floor(pt->x) + ray.modifier, floor(pt->y)))
			return (TRUE);
		pt->x = pt->x + ray.direction;
		pt->y = ray.pt_0->y_pos + (ray.pt_0->x_pos - pt->x) * -tan(true_angle);
	}
	return (FALSE);
}

static t_orientation	get_wall(double angle, char hit_axis)
{
	if (angle && hit_axis)
		return (N);
	return (S);
}

static void	set_ray_data(t_ray *ray, t_pt *hit_point, double start_x, char axis)
{
	ray->hit_x = hit_point->x;
	ray->hit_y = hit_point->y;
	ray->distance = fabs((start_x - hit_point->x) / cos(ray->true_angle));
	ray->wall = get_wall(ray->true_angle, axis);
	return ;
}

void	get_ray_data(t_cub3d *cub3d, t_ray *ray)
{
	t_pt	x_wall;
	t_pt	y_wall;
	double	x_dist;
	double	y_dist;

	x_dist = 0;
	y_dist = 0;
	if (!get_x_intersect(cub3d, &x_wall, ray->true_angle))
	{
		get_y_intersect(cub3d, &y_wall, ray->true_angle);
		return (set_ray_data(ray, &y_wall, cub3d->player->x_pos, 'y'));
	}
	if (!get_y_intersect(cub3d, &y_wall, ray->true_angle))
		return (set_ray_data(ray, &x_wall, cub3d->player->x_pos, 'x'));
	x_dist = fabs((cub3d->player->x_pos - x_wall.x) / cos(ray->true_angle));
	y_dist = fabs((cub3d->player->x_pos - y_wall.x) / cos(ray->true_angle));
	if (x_dist <= y_dist)
		set_ray_data(ray, &x_wall, cub3d->player->x_pos, 'x');
	else
		set_ray_data(ray, &y_wall, cub3d->player->x_pos, 'y');
	return ;
}
