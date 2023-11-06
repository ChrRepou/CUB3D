/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:20:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/06 21:42:32 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
#include "../../header_files/cub3d_raycasting.h"
#include "../../header_files/utils.h"

static int	get_wall_pixels(t_caster *cast_data, double dist, double ray_angle)
{
	int		wall_h_px;
	double	corrected_dist;

	corrected_dist = remove_distortion(dist, ray_angle);
	wall_h_px = (int)ceil(1 / corrected_dist * cast_data->proj_distance);
	return (wall_h_px);
}

// get-pixel_color
// void	get_texture_line(t_cub3d *cub3d, t_orientation orientation)
// {
// 	if (orientation == N)
// 	{

// 	}
// }
	//in addition to wall_h this needs collision_point and wall_hit
mlx_texture_t *get_texture(t_cub3d *cub3d, t_ray *ray_data)
{
	if (ray_data->wall == N)
		return (cub3d->info->north);
	if (ray_data->wall == S)
		return (cub3d->info->south);
	if (ray_data->wall == W)
		return (cub3d->info->west);
	else
		return(cub3d->info->east);	
}

int	get_texture_start(mlx_texture_t *tx, t_ray *ray_data)
{
	double			tile_x;
	
	if (ray_data->wall == N || ray_data->wall == S)
		tile_x = fmod(ray_data->hit_x, 1) * tx->width;	
	else
		tile_x = fmod(ray_data->hit_y, 1) * tx->width;
	return ((int)tile_x);
}

int	draw_texture_column(t_cub3d *cub3d, t_ray *ray_data, int ray_i, int y)
{
	mlx_texture_t	*tx;
	int				tx_x;
	int				wall_y;
	double			tx_step;
	double			tx_y;
	t_color			rgb;
	uint32_t 		color;

	wall_y = 0;
	tx_y = 0;
	tx = get_texture(cub3d, ray_data);
	tx_x = get_texture_start(tx, ray_data);
	tx_step = (double)tx->height / (double)ray_data->wall_h;
	while (wall_y < ray_data->wall_h)
	{
		rgb.red = tx->pixels[((int)tx_y * tx->width + tx_x) * 4];
		rgb.green = tx->pixels[((int)tx_y * tx->width + tx_x) * 4 + 1];
		rgb.blue = tx->pixels[((int)tx_y * tx->width + tx_x) * 4 + 2];
		color = rgb_to_color(rgb);
		my_put_pixel(cub3d->img, ray_i, y + wall_y, color);
		wall_y++;
		tx_y += tx_step;
	}
	return (wall_y - 1);
}


void	draw_column(t_cub3d *cub3d, double ray_angle, int ray_i)
{
	int			i;
	int			start_y;
	t_ray		ray_data;
	uint32_t	color;

	i = 0;
	ray_data.true_angle = get_true_angle(cub3d->player->angle, ray_angle);
	get_ray_data(cub3d, &ray_data);
	ray_data.wall_h = \
	get_wall_pixels(cub3d->raycaster, ray_data.distance, ray_angle);
	start_y = (HEIGHT - ray_data.wall_h) / 2;
	// if (ray_data.wall == N)
	// 	color = 0x93c4ffff;
	// if (ray_data.wall == S)
	// 	color = 0xb3efc0ff;
	// if (ray_data.wall == W)
	// 	color = 0xbdffecff;
	// if (ray_data.wall == E)
		color = 0xceffe3ff;
	// printf("RAY DATA: \n");
	// printf("true_angle: [%f]\n", ray_data.true_angle);
	// printf("hitpoint: ([%f], [%f])\n", ray_data.hit_x, ray_data.hit_y);
	// printf("distance: [%f]\n", ray_data.distance);
	// printf("wall direction and height : [%d][%d]\n", ray_data.wall, ray_data.wall_h);
	while (i < HEIGHT)
	{
		if (i < start_y)
			my_put_pixel(cub3d->img, ray_i, i, cub3d->info->celing_color);
		else if (i >= start_y && i < start_y + ray_data.wall_h)
			i += draw_texture_column(cub3d, &ray_data, ray_i, i);
			// my_put_pixel(cub3d->img, ray_i, i, color);
		else
			my_put_pixel(cub3d->img, ray_i, i, cub3d->info->floor_color);
		i++;
	}

}
