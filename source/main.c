/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:46 by crepou            #+#    #+#             */
/*   Updated: 2023/11/04 19:22:38 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"
#include "../header_files/cub3d_minimap.h"
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


	init_minimap(&cub3d_data, &minimap);
	draw_minimap(&cub3d_data, &minimap);
	mlx_key_hook(cub3d_data.window, &esc_keyfunc, (void *)cub3d_data.window);
	mlx_loop_hook(cub3d_data.window, (void (*)(void *))gen_hooks, &cub3d_data);
	mlx_loop(cub3d_data.window);
	mlx_delete_image(cub3d_data.window, cub3d_data.img);
	mlx_delete_image(cub3d_data.window, cub3d_data.north_img);
	mlx_delete_image(cub3d_data.window, cub3d_data.south_img);
	mlx_delete_image(cub3d_data.window, cub3d_data.east_img);
	mlx_delete_image(cub3d_data.window, cub3d_data.west_img);
	mlx_delete_image(cub3d_data.window, minimap.img_mini);
	mlx_delete_image(cub3d_data.window, minimap.img_player);
	mlx_terminate(cub3d_data.window);
	free_map_info(&cub3d_data);
	// system("leaks cub3d");
	return (0);
}
