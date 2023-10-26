/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:50:06 by crepou            #+#    #+#             */
/*   Updated: 2023/10/26 13:05:13 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

/*
The function returns all the 3 colors of rgb into one integer color
*/
int	rgb_to_color(t_color c)
{
	int	color;

	color = (c.red << 16) | (c.green << 8) | c.blue;
	return (color);
}

/*
The function takes an integer color and extracts the r g b values
*/
t_color	*color_to_rgb(int color)
{
	t_color	*c;

	c = (t_color *)malloc(sizeof(t_color));
	if (!c)
		return (NULL);
	c->red = (color >> 16) & 0xFF;
	c->green = (color >> 8) & 0xFF;
	c->blue = color & 0xFF;
	return (c);
}
