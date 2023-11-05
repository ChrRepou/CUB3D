/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:46 by crepou            #+#    #+#             */
/*   Updated: 2023/11/05 20:10:09 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"
#include "../header_files/cub3d_raycasting.h"
#include "../header_files/utils.h"


int	main(int argc, char *argv[])
{
	int			fd;
	t_cub3d		cub3d_data;
	t_minimap	minimap;
	t_caster	cast_data;

	fd = is_input_valid(argc, argv);
	if (!fd)
		return (-1);
	if (!read_file(fd, &cub3d_data))
		return (-1);
	replace_spaces(&cub3d_data);
	printf("MAP AFTER REPLACEMENT:\n");
	print_map(&cub3d_data);
	printf("x:%f, y:%f\n", cub3d_data.player->x_pos, cub3d_data.player->y_pos);
	printf("orientation: %d, angle: %f\n", cub3d_data.player->orientation, cub3d_data.player->angle);
	
	initiate_cub3d(&cub3d_data, &cast_data);
	//if fails, delete mages, teminate window, free parsing data, exit here

	init_minimap(&cub3d_data, &minimap);
	draw_minimap(&cub3d_data, &minimap);
	//I think we should have bonus rule for minimap...
	mlx_key_hook(cub3d_data.window, &esc_keyfunc, (void *)cub3d_data.window);
	mlx_loop_hook(cub3d_data.window, (void (*)(void *))gen_hooks, &cub3d_data);
	mlx_loop(cub3d_data.window);
	delete_images(&cub3d_data, &minimap);
	mlx_terminate(cub3d_data.window);
	free_map_info(&cub3d_data);
	// system("leaks cub3d");
	return (0);
}
