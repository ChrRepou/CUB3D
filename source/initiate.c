/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:10 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/15 17:19:47 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	initiate_textures(t_cub3d *cub3d)
{
	cub3d->info->north = mlx_load_png(cub3d->info->north_texture);
	if (!cub3d->info->north)
	{
		printf("Error loading the texture: %s\n", cub3d->info->north_texture);
		return (FALSE);
	}
	cub3d->info->south = mlx_load_png(cub3d->info->south_texture);
	if (!cub3d->info->south)
	{
		printf("Error loading the texture: %s\n", cub3d->info->south_texture);
		return (FALSE);
	}
	cub3d->info->east = mlx_load_png(cub3d->info->east_texture);
	if (!cub3d->info->east)
	{
		printf("Error loading the texture: %s\n", cub3d->info->east_texture);
		return (FALSE);
	}
	cub3d->info->west = mlx_load_png(cub3d->info->west_texture);
	if (!cub3d->info->west)
	{
		printf("Error loading the texture: %s\n", cub3d->info->west_texture);
		return (FALSE);
	}
	return (TRUE);
}

int	initiate_mlx(t_cub3d *cub3d_data)
{
	cub3d_data->window = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!cub3d_data->window)
	{
		printf("Error while creating a window\n");
		return (FALSE);
	}
	cub3d_data->img = mlx_new_image(cub3d_data->window, WIDTH, HEIGHT);
	if (!cub3d_data->img)
	{
		printf("Error while creating an image\n");
		return (FALSE);
	}
	if (mlx_image_to_window(cub3d_data->window, cub3d_data->img, 0, 0) < 0)
	{
		printf("Error while putting rhe image to the window\n");
		return (FALSE);
	}
	return (TRUE);
}
