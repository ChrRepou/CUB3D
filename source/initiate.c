/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:10 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/27 21:08:55 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int initiate_window(t_displ *s_displ)
{
	s_displ->window = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	if (!s_displ->window)
	{
		printf("error while creating a window\n");
		//free everything;
		exit(EXIT_FAILURE);
	}
	s_displ->img = mlx_new_image(s_displ->window, WIDTH, HEIGHT);
	if (!s_displ->img)
	{
		printf("error creating the image\n");
		exit(EXIT_FAILURE);
	}
	ft_memset(s_displ->img->pixels, 233, s_displ->img->width * s_displ->img->height * sizeof(int32_t));
	ft_memset(s_displ->img->pixels, 255, s_displ->img->width * s_displ->img->height * sizeof(int32_t) / 2);
		if (mlx_image_to_window(s_displ->window, s_displ->img, 0, 0) < 0)
	{
		printf("error displaying the image\n");
		//free everything;
		exit(EXIT_FAILURE);
	}
	return (0);
}
