/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:10 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/04 20:10:31 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"


void	error_free_exit(char *error_msg, char **map)
{
	printf("%s\n", error_msg);
	if (map)
		free_after_split(map); // there is more to free!
	exit (EXIT_FAILURE);
}

static mlx_image_t	*texture_to_img(mlx_t *mlx, char *path)
{
	xpm_t		*texture_s;
	mlx_image_t	*texture_as_img;

	texture_s = mlx_load_xpm42(path);
	if (!texture_s)
		return (NULL);
	texture_as_img = mlx_texture_to_image(mlx, &texture_s->texture);
	mlx_delete_texture(&texture_s->texture);
	if (!texture_as_img)
		return (NULL);
	return (texture_as_img);
}

static int	initiate_textures(t_cub3d *cub3d)
{
	cub3d->north_img = \
	texture_to_img(cub3d->window, cub3d->info->north_texture);
	//if NULL --> error message, terminate previous?, return 1
	cub3d->south_img = \
	texture_to_img(cub3d->window, cub3d->info->south_texture);
	//if NULL --> error message, terminate previous?, return 1
	cub3d->east_img = \
	texture_to_img(cub3d->window, cub3d->info->east_texture);
	//if NULL --> error message, terminate previous?, return 1
	cub3d->west_img = \
	texture_to_img(cub3d->window, cub3d->info->west_texture);
	//if NULL --> error message, terminate previous?, return 1
	return (0);
}

int	initiate_window(t_cub3d *cub3d_data)
{
	cub3d_data->window = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	if (!cub3d_data->window)
		error_free_exit("error while creating a window", cub3d_data->map);
	cub3d_data->img = mlx_new_image(cub3d_data->window, WIDTH, HEIGHT);
	if (!cub3d_data->img)
	{
		mlx_terminate(cub3d_data->window);
		error_free_exit("error creating the image", cub3d_data->map);
	}
	if (mlx_image_to_window(cub3d_data->window, cub3d_data->img, 0, 0) < 0)
	{
		mlx_delete_image(cub3d_data->window, cub3d_data->img);
		mlx_terminate(cub3d_data->window);
		error_free_exit("error displaying the image", cub3d_data->map);
	}
	return (0);
}

int	initiate_mlx(t_cub3d *cub3d_data)
{
	if (initiate_window(cub3d_data) != 0)
		return (EXIT_FAILURE);
	if (initiate_textures(cub3d_data) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
