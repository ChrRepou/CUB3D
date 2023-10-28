/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:20:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/28 20:01:51 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
#include "../../header_files/cub3d_raycasting.h"





static double	get_x_dist(t_player *player, char **map, int map_w, int map_h, double true_angle)
{
	t_ray	ray;

	ray.modifier = 0;
	ray.direction = 1;
	if (fabs(true_angle) < ANGLE_TOLERANCE || \
		fabs(fabs(true_angle) - M_PI) < ANGLE_TOLERANCE)
		return (-1);
	if (true_angle < M_PI)
		ray.hit_y = ceil(player->y_pos);
	else
	{
		ray.hit_y = floor(player->y_pos);
		ray.modifier = -1;
		ray.direction = -1;
	}
	ray.hit_x = \
		player->x_pos + (player->y_pos - ray.hit_y) / -tan(true_angle);
	while (ray.hit_x >= 0 && ray.hit_x <= map_w - 1 && ray.hit_y <= map_h)
	{
		if (wall_hit(map, floor(ray.hit_x), floor(ray.hit_y) + ray.modifier))
			return (fabs((player->y_pos - ray.hit_y) / sin(true_angle)));
		ray.hit_y = ray.hit_y + ray.direction;
		ray.hit_x = player->x_pos + (player->y_pos - ray.hit_y) / -tan(true_angle);
	}
	return (-1);
}

static double	get_y_dist(t_player *player, char **map, int map_w, int map_h, double true_angle)
{
	t_ray	ray;

	ray.modifier = 0;
	ray.direction = 1;
	if (fabs(fabs(true_angle) - M_PI / 2.0) < ANGLE_TOLERANCE || \
		fabs(fabs(true_angle) - 3.0 * M_PI / 2.0) < ANGLE_TOLERANCE)
		return (-1);
	if (true_angle > M_PI / 2 && true_angle < 3 * M_PI / 2)
	{
		ray.hit_x = floor(player->x_pos);
		ray.modifier = -1;
		ray.direction = -1;
	}
	else
		ray.hit_x = ceil(player->x_pos);
	ray.hit_y = \
		player->y_pos + (player->x_pos - ray.hit_x) * -tan(true_angle);
	while (ray.hit_y >= 0 && ray.hit_y <= map_h - 1 && ray.hit_x <= map_w)
	{
		if (wall_hit(map, floor(ray.hit_x) + ray.modifier, floor(ray.hit_y)))
			return (fabs((player->x_pos - ray.hit_x) / cos(true_angle)));
		ray.hit_x = ray.hit_x + ray.direction;
		ray.hit_y = player->y_pos + (player->x_pos - ray.hit_x) * -tan(true_angle);
	}
	return (-1);
}

/*formula is:
 projected_column_h = 
 actual_column_h/distance_to_column * distance_to_projection_plane
 actual_column heigth is 1 map unit and distance is already in map units,
 distance_to_the_projection_plane includes also the value of one map unit.
 */
static int	get_wall_pixels(t_caster *cast_data, double dist, double ray_angle)
{
	int		wall_h_px;
	double	corrected_dist;

	corrected_dist = remove_distortion(dist, ray_angle);
	printf("distance %f, corrected distance %f\n", dist, corrected_dist);
	wall_h_px = (int)ceil(1 / corrected_dist * cast_data->proj_distance);
	return (wall_h_px);
}

int	get_column_data(t_cub3d *cub3d_data, double ray_angle)
{
	double	x_dist;
	double	y_dist;
	double	true_angle;

	true_angle = get_true_angle(cub3d_data->player->angle, ray_angle);
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

	//in addition to wall_h this needs collision_point and wall_hit
void	draw_column(t_cub3d *cub3d_data, double ray_angle, int ray_i)
{
	int		wall_h;
	int 	start_y;
	int		i;
	// t_ray	ray_data;
	
	wall_h = get_column_data(cub3d_data, ray_angle);
	printf("wall h %d\n", wall_h);
	start_y = (HEIGHT - wall_h) / 2;
	i = 0;
	while (i < wall_h)
		my_put_pixel(cub3d_data->img, ray_i, (start_y + i++), 0xfff4dbff);
}


// ray data should contain:
// hitpoint x,
// hitpoint y,
// wall that has been hit;
// wall_h,