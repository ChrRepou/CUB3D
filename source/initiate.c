/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:10 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/27 16:53:36 by tmarts           ###   ########.fr       */
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
	s_displ->image = mlx_new_image(s_displ->window, WIDTH, HEIGHT);
	if (!s_displ->image)
	{
		printf("error creating the image\n");
		exit(EXIT_FAILURE);
	}
		if (mlx_image_to_window(s_displ->window, s_displ->image, 0, 0) < 0)
	{
		printf("error displaying the image\n");
		//free everything;
		exit(EXIT_FAILURE);
	}
	return (0);
}
