/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:22:26 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/02 19:57:22 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

typedef struct s_minimap
{
	int			x_px;
	int			y_px;
	int			x_tile;
	int			y_tile;
	int			tile_h;
	uint32_t	color;
}	t_minimap;

static void	draw_tile(mlx_image_t *img, t_minimap *data)
{
	int	max_y;
	int	max_x;
	int	x_start;

	max_y = data->y_px + data->tile_h;
	max_x = data->x_px + data->tile_h;
	x_start = data->x_px;
	while (data->y_px < max_y)
	{
		if (data->x_px < WIDTH && data->y_px < HEIGHT && \
		data->x_px > 0 && data->y_px > 0)
			mlx_put_pixel(img, data->x_px++, data->y_px, data->color);
		if (data->x_px == max_x)
		{
			data->x_px = x_start;
			data->y_px++;
		}
	}
}



void draw_player(mlx_image_t *img, )
{	
	color = 0xE00016FF;
	int radius;
	radius = square_side / 2;

    int i;
    int j;

    i = x - radius;
    while (i <= x + radius)
    {
        j = y - radius;
        while (j <= y + radius)
        {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius)
                mlx_put_pixel(img, i, j, color);
            j++;
        }
        i++;
    }
}

	int map[24][24]=
	{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,N,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

int	draw_minimap(mlx_image_t *img, t_cub3d *data)
{	
	t_minimap	mmap;

	mmap.tile_h = get_square_side(data->width, data->height);
	mmap.x_px = 0;
	mmap.y_px = 0;
	mmap.x_tile = 0;
	mmap.y_tile = 0;
	while (mmap.y_tile < data->height)
	{
		while (mmap.x_tile < data->width)
		{
			if (map[mmap.y_tile][mmap.x_tile] == 1)
				mmap.color = 0x1CFF8AFF;
			else
				mmap.color = 0x15164AFF;
			draw_square(img, &mmap);
			mmap.x_tile++;
			mmap.x_px = mmap.x_px + mmap.tile_h;
		}
		mmap.y_px = mmap.y_px + mmap.tile_h;
		mmap.x_tile = 0;
		mmap.x_px = 0;
		mmap.y_tile++;
	}
	draw_player(img, s_map->player.x_position, s_map->player.y_position, mmap.tile_h);
	return (0);
}
