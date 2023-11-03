/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:51:10 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/03 17:56:08 by tmarts           ###   ########.fr       */
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
