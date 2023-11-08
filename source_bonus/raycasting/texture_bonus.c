/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:31:06 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/08 18:08:44 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files_bonus/cub3d_bonus.h"
#include "../../header_files_bonus/cub3d_raycasting_bonus.h"

static int	get_texture_start_x(mlx_texture_t *tx, t_ray *ray_data)
{
	double	tile_x;

	if (ray_data->wall == N || ray_data->wall == S)
		tile_x = fmod(ray_data->hit_x, 1) * tx->width;
	else
		tile_x = fmod(ray_data->hit_y, 1) * tx->width;
	return ((int)tile_x);
}

static double	get_texture_start_y(mlx_texture_t *tx, int start_y, int wall_h)
{
	double	tile_y;

	if (start_y >= 0)
		return (0);
	tile_y = (double)tx->height / (double)wall_h * (double)abs(start_y);
	return (tile_y);
}

int	draw_texture_column(t_cub3d *cub3d, t_ray *ray, int ray_i, int y_start)
{
	int		tx_x;
	int		y;
	double	tx_step;
	double	tx_y;
	int		tx_index;		

	tx_y = get_texture_start_y(ray->texture, y_start, ray->wall_h);
	tx_x = get_texture_start_x(ray->texture, ray);
	if (y_start < 0)
		y_start = 0;
	y = y_start;
	tx_index = ((int)tx_y * ray->texture->width + tx_x) * sizeof(int32_t);
	tx_step = (double)ray->texture->height / (double)ray->wall_h;
	while (y < y_start + ray->wall_h && y < HEIGHT)
	{
		ft_memcpy(&cub3d->img->pixels[(y * WIDTH + ray_i) * sizeof(int32_t)], \
		&ray->texture->pixels[tx_index], sizeof(int32_t));
		y++;
		tx_y += tx_step;
		tx_index = ((int)tx_y * ray->texture->width + tx_x) * sizeof(int32_t);
	}
	return (y - y_start - 1);
}
