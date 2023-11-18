/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_ray_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:20:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/18 17:14:01 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files_bonus/cub3d_bonus.h"
#include "../../header_files_bonus/cub3d_raycasting_bonus.h"

/*sets the initial data to find the wall intersections, including
the direction of the ray (increment either neg or pos) and
modifier that indicates the inner edge of the wall block*/
static void	set_vector_data(t_ray_utils *utils, double angle, char axis)
{
	utils->modifier = 0;
	utils->increment_y = 1;
	utils->increment_x = 1;
	if (axis == 'x')
	{
		if (angle > M_PI && angle < 2 * M_PI)
		{
			utils->modifier = -1;
			utils->increment_y = -1;
		}
		if (fabs(angle - M_PI_2) < EPSILON || \
			fabs(angle - 3.0 * M_PI_2) < EPSILON)
			utils->increment_x = 0;
		else
			utils->increment_x = utils->increment_y / tan(angle);
	}
	else
	{
		if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		{
			utils->modifier = -1;
			utils->increment_x = -1;
		}
		utils->increment_y = utils->increment_x * tan(angle);
	}
}

/*finds the point on the map where ray intersects a wall on x axis.
Returns FALSE when intersection does not happen*/
static int	get_x_intersect(t_cub3d *cub3d, t_pt *pt, double angle)
{
	t_ray_utils	utils;

	if (fabs(angle) < ANGLE_TOLERANCE || \
		fabs(angle - M_PI) < ANGLE_TOLERANCE)
		return (FALSE);
	utils.pt_0 = cub3d->player;
	set_vector_data(&utils, angle, 'x');
	if (utils.increment_y > 0)
		pt->y = ceil(utils.pt_0->y_pos);
	else
		pt->y = floor(utils.pt_0->y_pos);
	if (fabs(utils.pt_0->y_pos - floor(utils.pt_0->y_pos)) < EPSILON)
		pt->y = pt->y + utils.increment_y;
	if (utils.increment_x != 0)
		pt->x = utils.pt_0->x_pos + (utils.pt_0->y_pos - pt->y) / -tan(angle);
	else
		pt->x = utils.pt_0->x_pos;
	while (valid_coords(pt, cub3d->width, cub3d->height))
	{
		if (is_wall_hit(cub3d->map, (int)pt->x, (int)pt->y + utils.modifier))
			return (TRUE);
		pt->y += utils.increment_y;
		pt->x += utils.increment_x;
	}
	return (FALSE);
}

/*finds the point on the map where ray intersects a wall on y axis.
Returns FALSE when intersection does not happen*/
static int	get_y_intersect(t_cub3d *cub3d, t_pt *pt, double angle)
{
	t_ray_utils	utils;

	if (fabs(angle - M_PI_2) < ANGLE_TOLERANCE || \
		fabs(angle - 3.0 * M_PI_2) < ANGLE_TOLERANCE)
		return (FALSE);
	utils.pt_0 = cub3d->player;
	set_vector_data(&utils, angle, 'y');
	if (utils.increment_x > 0)
		pt->x = ceil(utils.pt_0->x_pos);
	else
		pt->x = floor(utils.pt_0->x_pos);
	if (fabs(utils.pt_0->x_pos - floor(utils.pt_0->x_pos)) < EPSILON)
		pt->x = pt->x + utils.increment_x;
	pt->y = utils.pt_0->y_pos + (pt->x - utils.pt_0->x_pos) * tan(angle);
	while (valid_coords(pt, cub3d->width, cub3d->height))
	{
		if (is_wall_hit(cub3d->map, (int)pt->x + utils.modifier, (int)pt->y))
			return (TRUE);
		pt->x += utils.increment_x;
		pt->y += utils.increment_y;
	}
	return (FALSE);
}

static void	set_ray_data(t_ray *ray, t_pt *hit_point, t_player *st, char axis)
{
	ray->hit_x = hit_point->x;
	ray->hit_y = hit_point->y;
	if (axis == 'x')
		ray->distance = fabs((st->y_pos - hit_point->y) / sin(ray->true_angle));
	else if (axis == 'y')
		ray->distance = fabs((st->x_pos - hit_point->x) / cos(ray->true_angle));
	ray->wall = get_wall(ray->true_angle, axis);
	return ;
}

/*compares the x and y axis intersections finding the actual hit point, 
calculates and sets the values to the variables in t_ray s_sray struct*/
void	get_ray_data(t_cub3d *cub3d, t_ray *ray, double ray_angle)
{
	t_pt	x_wall;
	t_pt	y_wall;
	double	x_dist;
	double	y_dist;

	x_dist = 0;
	y_dist = 0;
	ray->true_angle = get_true_angle(cub3d->player->angle, ray_angle);
	if (!get_x_intersect(cub3d, &x_wall, ray->true_angle))
	{
		get_y_intersect(cub3d, &y_wall, ray->true_angle);
		return (set_ray_data(ray, &y_wall, cub3d->player, 'y'));
	}
	if (!get_y_intersect(cub3d, &y_wall, ray->true_angle))
	{
		return (set_ray_data(ray, &x_wall, cub3d->player, 'x'));
	}
	x_dist = fabs((cub3d->player->x_pos - x_wall.x) / cos(ray->true_angle));
	y_dist = fabs((cub3d->player->x_pos - y_wall.x) / cos(ray->true_angle));
	if (x_dist <= y_dist)
		set_ray_data(ray, &x_wall, cub3d->player, 'x');
	else
		set_ray_data(ray, &y_wall, cub3d->player, 'y');
	return ;
}
