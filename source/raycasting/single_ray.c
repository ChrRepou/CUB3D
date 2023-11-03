/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:20:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/03 15:43:47 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
#include "../../header_files/cub3d_raycasting.h"

static int	get_wall_pixels(t_caster *cast_data, double dist, double ray_angle)
{
	int		wall_h_px;
	double	corrected_dist;

	corrected_dist = remove_distortion(dist, ray_angle);
	wall_h_px = (int)ceil(1 / corrected_dist * cast_data->proj_distance);
	return (wall_h_px);
}

// get-pixel_color

	//in addition to wall_h this needs collision_point and wall_hit
void	draw_column(t_cub3d *cub3d_data, double ray_angle, int ray_i)
{
	int		i;
	int		start_y;
	t_ray	ray_data;

	i = 0;
	ray_data.true_angle = get_true_angle(cub3d_data->player->angle, ray_angle);
	get_ray_data(cub3d_data, &ray_data);
	ray_data.wall_h = \
	get_wall_pixels(cub3d_data->raycaster, ray_data.distance, ray_angle);
	start_y = (HEIGHT - ray_data.wall_h) / 2;
	// printf("RAY DATA: \n");
	// printf("true_angle: [%f]\n", ray_data.true_angle);
	// printf("hitpoint: ([%f], [%f])\n", ray_data.hit_x, ray_data.hit_y);
	// printf("distance: [%f]\n", ray_data.distance);
	// printf("wall direction and height : [%d][%d]\n", ray_data.wall, ray_data.wall_h);
	while (i < ray_data.wall_h)
		my_put_pixel(cub3d_data->img, ray_i, (start_y + i++), 0xfff4dbff);
}
