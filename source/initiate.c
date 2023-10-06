/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:10 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/06 19:44:52 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	initiate_window(t_cub3d *cub3d_data)
{
	cub3d_data->window = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	if (!cub3d_data->window)
	{
		printf("error while creating a window\n");
		//free everything;
		exit(EXIT_FAILURE);
	}
	cub3d_data->img = mlx_new_image(cub3d_data->window, WIDTH, HEIGHT);
	if (!cub3d_data->img)
	{
		printf("error creating the image\n");
		exit(EXIT_FAILURE);
	}
	ft_memset(cub3d_data->img->pixels, 255, cub3d_data->img->width * cub3d_data->img->height * sizeof(int32_t));
	if (mlx_image_to_window(cub3d_data->window, cub3d_data->img, 0, 0) < 0)
	{
		printf("error displaying the image\n");
		//free everything;
		exit(EXIT_FAILURE);
	}
	return (0);
}
