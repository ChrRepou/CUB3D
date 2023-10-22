/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:24:17 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/21 18:01:36 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
#include "../../header_files/cub3d_minimap.h"

static t_2d	get_endpoint(t_2d start_pt, double angle, int length)
{
	t_2d	end_pt;

	end_pt.x = round(start_pt.x + (length * cos(angle * M_PI / 180)));
	end_pt.y = round(start_pt.y + (length * sin(angle * M_PI / 180)));
	return (end_pt);
}

static void	draw_direction(mlx_image_t *img, double angle)
{
	t_2d	start_pt;
	t_2d	end_pt;

	start_pt.x = img->height / 2;
	start_pt.y = img->height / 2;
	start_pt.pt_rgba = PLAYER_COLOR;
	end_pt.pt_rgba = PLAYER_COLOR;
	end_pt = get_endpoint(start_pt, angle, img->height / 4);
	draw_line(img, start_pt, end_pt);
}

void	draw_player(mlx_image_t *img, double angle)
{
	int	x_px;
	int	y_px;
	int	x_start;
	int	end;

	ft_memset(img->pixels, 0, img->width * img->height * sizeof(int32_t));
	x_px = img->height / 2 - 2;
	y_px = img->height / 2 - 2;
	end = img->height / 2 + 3;
	x_start = x_px;
	while (y_px <= end)
	{
		mlx_put_pixel(img, x_px++, y_px, PLAYER_COLOR);
		if (x_px == end)
		{
			x_px = x_start;
			y_px++;
		}
	}
	draw_direction(img, angle);
}
