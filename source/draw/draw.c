/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:00:45 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/07 19:59:53 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

void	my_put_pixel(mlx_image_t *image, int x, int y, uint32_t color)
{
	if (x >= 0 && x < (int)image->width && y >= 0 && y < (int)image->height)
		mlx_put_pixel(image, x, y, color);
}
