/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_ray_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:20:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/15 15:33:31 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files_bonus/cub3d_bonus.h"
#include "../../header_files_bonus/cub3d_raycasting_bonus.h"

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

static mlx_texture_t	*get_door(t_cub3d *cub3d, int x, int y)
{
	mlx_texture_t	*tx;

	tx = NULL;
	if (cub3d->map[y][x] == '2')
		tx = cub3d->info->closed_door;
	return (tx);
}

/*returns a texture pointer corresponding to the wall the ray intersects*/
static mlx_texture_t	*get_texture(t_cub3d *cub3d, t_ray *ray)
{
	mlx_texture_t	*right_tx;

	right_tx = NULL;
	if (ray->wall == N)
	{
		right_tx = get_door(cub3d, (int)ray->hit_x, (int)ray->hit_y - 1);
		if (!right_tx)
			return (cub3d->info->north);
	}
	else if (ray->wall == W)
	{
		right_tx = get_door(cub3d, (int)ray->hit_x - 1, (int)ray->hit_y);
		if (!right_tx)
			return (cub3d->info->west);
	}
	else if (ray->wall == S || ray->wall == E)
	{
		right_tx = get_door(cub3d, (int)ray->hit_x, (int)ray->hit_y);
		if (!right_tx && ray->wall == S)
			return (cub3d->info->south);
		else if (!right_tx && ray->wall == E)
			return (cub3d->info->east);
	}
	return (right_tx);
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
	ray_data.texture = get_texture(cub3d, &ray_data);
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
