/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:46 by crepou            #+#    #+#             */
/*   Updated: 2023/09/30 19:00:53 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"


int	main(int argc, char *argv[])
{
	int		fd;
	t_cub3d	cub3d_data;

	fd = is_input_valid(argc, argv);
	if (!fd)
		return (-1);
	//parsing happening here, if successful:
	initiate_window(&cub3d_data);
	mlx_key_hook(cub3d_data.window, &esc_keyfunc, (void *)cub3d_data.window);
	// mlx_loop_hook(cub3d_data.window, (void (*)(void *))generic_hooks, &cub3d_data);
	mlx_loop(cub3d_data.window);
	mlx_delete_image(cub3d_data.window, cub3d_data.img);
	mlx_terminate(cub3d_data.window);
	return (0);
}



