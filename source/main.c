/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:46 by crepou            #+#    #+#             */
/*   Updated: 2023/10/21 20:50:02 by crepou           ###   ########.fr       */
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
	if (!read_file(fd, &cub3d_data))
		return (-1);
	replace_spaces(&cub3d_data);
	printf("MAP AFTER REPLACEMENT:\n");
	print_map(&cub3d_data);
	//parsing happening here, if successful:
	initiate_window(&cub3d_data);
	mlx_key_hook(cub3d_data.window, &esc_keyfunc, (void *)cub3d_data.window);
	// mlx_loop_hook(cub3d_data.window, (void (*)(void *))generic_hooks, &cub3d_data);
	mlx_loop(cub3d_data.window);
	mlx_delete_image(cub3d_data.window, cub3d_data.img);
	mlx_terminate(cub3d_data.window);
	//free_map_info(&cub3d_data);
	return (0);
}



