/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:20:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/07 17:37:45 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
#include "../../header_files/cub3d_raycasting.h"
#include "../../header_files/utils.h"

/*removes distortion and 
returns the relative height of the wall (in pixels) to be drawn*/
static int	get_wall_pixels(t_caster *cast_data, double dist, double ray_angle)
{
	int		wall_h_px;
	double	corrected_dist;

	corrected_dist = remove_distortion(dist, ray_angle);
	wall_h_px = (int)ceil(1 / corrected_dist * cast_data->proj_distance);
	return (wall_h_px);
}

/*returns a texture pointer corresponding to the wall the ray intersects*/
static mlx_texture_t	*get_texture(t_cub3d *cub3d, t_orientation wall)
{
	if (wall == N)
		return (cub3d->info->north);
	if (wall == S)
		return (cub3d->info->south);
	if (wall == W)
		return (cub3d->info->west);
	else
		return (cub3d->info->east);
}

/*draws the  column of pixels that corresponds to one cast ray*/
void	draw_column(t_cub3d *cub3d, double ray_angle, int ray_i)
{
	int			i;
	int			start_y;
	t_ray		ray_data;

	i = 0;
	get_ray_data(cub3d, &ray_data, ray_angle);
	ray_data.wall_h = \
	get_wall_pixels(cub3d->raycaster, ray_data.distance, ray_angle);
	ray_data.texture = get_texture(cub3d, ray_data.wall);
	start_y = (HEIGHT - ray_data.wall_h) / 2;
	while (i < HEIGHT)
	{
		if (i < start_y)
			my_put_pixel(cub3d->img, ray_i, i, cub3d->info->celing_color);
		else if (i >= start_y && i < start_y + ray_data.wall_h)
			i += draw_texture_column(cub3d, &ray_data, ray_i, start_y);
		else
			my_put_pixel(cub3d->img, ray_i, i, cub3d->info->floor_color);
		i++;
	}
}
