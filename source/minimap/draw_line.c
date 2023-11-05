/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:58:02 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/05 21:18:17 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

/*places pixels to draw a line, 
following Bresenhams algorithm*/

static void	draw_line_low(mlx_image_t *img, t_2d s_p1, t_2d s_p2, t_px *s_px)
{
	int	p;
	int	start;

	start = s_p1.x;
	s_px->dx = s_p2.x - s_p1.x;
	s_px->dy = s_p2.y - s_p1.y;
	if (s_px->dy < 0)
		s_px->step = -1;
	p = 2 * s_px->dy * s_px->step - s_px->dx;
	while (s_p1.x < s_p2.x)
	{
		if (s_p1.x < (int)img->width && s_p1.y < (int)img->height \
			&& s_p1.x > 0 && s_p1.y > 0)
			mlx_put_pixel(img, s_p1.x++, s_p1.y, PLAYER_COLOR);
		else
			s_p1.x++;
		if (p < 0)
			p = p + 2 * s_px->dy * s_px->step;
		else
		{
			p = p + 2 * s_px->dy * s_px->step - 2 * s_px->dx;
			s_p1.y = s_p1.y + s_px->step;
		}
	}
}

static void	draw_line_high(mlx_image_t *img, t_2d s_p1, t_2d s_p2, t_px *s_px)
{
	int	p;
	int	start;

	start = s_p1.y;
	s_px->dx = s_p2.x - s_p1.x;
	s_px->dy = s_p2.y - s_p1.y;
	if (s_px->dx < 0)
		s_px->step = -1;
	p = 2 * s_px->dx * s_px->step - s_px->dy;
	while (s_p1.y < s_p2.y)
	{
		if (s_p1.x < (int)img->width && s_p1.y < (int)img->height \
			&& s_p1.x > 0 && s_p1.y > 0)
			mlx_put_pixel(img, s_p1.x, s_p1.y++, PLAYER_COLOR);
		else
			s_p1.y++;
		if (p < 0)
			p = p + 2 * s_px->dx * s_px->step;
		else
		{
			p = p + 2 * s_px->dx * s_px->step - 2 * s_px->dy;
			s_p1.x = s_p1.x + s_px->step;
		}
	}
}


void	draw_line(mlx_image_t *img, t_2d s_p1, t_2d s_p2)
{
	t_px	pixel;

	pixel.step = 1;
	if (abs(s_p2.y - s_p1.y) < abs(s_p2.x - s_p1.x))
	{
		if (s_p1.x > s_p2.x)
			draw_line_low(img, s_p2, s_p1, &pixel);
		else
			draw_line_low(img, s_p1, s_p2, &pixel);
	}
	else
	{
		if (s_p1.y > s_p2.y)
			draw_line_high(img, s_p2, s_p1, &pixel);
		else
			draw_line_high(img, s_p1, s_p2, &pixel);
	}
}

