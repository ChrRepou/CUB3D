/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:22:26 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/15 15:29:27 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files_bonus/cub3d_bonus.h"
#include "../../header_files_bonus/cub3d_minimap_bonus.h"

static void	init_minimap_draw(t_mini_draw *s_minimap)
{
	s_minimap->x_px = 0;
	s_minimap->y_px = 0;
	s_minimap->x_tile = 0;
	s_minimap->y_tile = 0;
}

/*Draws one tile of the minimap*/
static void	draw_tile(mlx_image_t *img, t_mini_draw *data, int tile_h)
{
	int	max_y;
	int	max_x;
	int	x_start;

	max_y = data->y_px + tile_h;
	max_x = data->x_px + tile_h;
	x_start = data->x_px;
	while (data->y_px < max_y)
	{
		if ((data->x_px < MINI_W && data->x_px >= 0) \
		&& (data->y_px < MINI_H && data->y_px >= 0))
			mlx_put_pixel(img, data->x_px++, data->y_px, data->color);
		if (data->x_px == max_x)
		{
			data->x_px = x_start;
			data->y_px++;
		}
	}
}

void	draw_minimap(t_cub3d *data)
{
	t_mini_draw	mmap;

	init_minimap_draw(&mmap);
	while (mmap.y_tile < data->height)
	{
		while (mmap.x_tile < data->width)
		{
			if (data->map[mmap.y_tile][mmap.x_tile] == '1')
				mmap.color = WALL_COLOR;
			else if (data->map[mmap.y_tile][mmap.x_tile] == '2' || \
					data->map[mmap.y_tile][mmap.x_tile] == '3')
				mmap.color = DOOR_COLOR;
			else
				mmap.color = SPACE_COLOR;
			draw_tile(data->minimap->img_mini, &mmap, data->minimap->tile_h);
			mmap.x_tile++;
			mmap.x_px = mmap.x_px + data->minimap->tile_h;
			mmap.y_px = mmap.y_tile * data->minimap->tile_h;
		}
		mmap.y_px = mmap.y_px + data->minimap->tile_h;
		mmap.x_tile = 0;
		mmap.x_px = 0;
		mmap.y_tile++;
	}
	return ;
}
