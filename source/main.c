/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:46 by crepou            #+#    #+#             */
/*   Updated: 2023/11/06 14:45:49 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d_minimap.h"
#include "../header_files/cub3d_raycasting.h"
#include "../header_files/utils.h"

void	leaks( void )
{
	system("leaks cub3d");
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_cub3d		cub3d_data; //change
	t_minimap	minimap;
	t_caster	cast_data;

	//atexit(leaks);
	fd = is_input_valid(argc, argv);
	if (!fd)
		return (-1);
	if (!read_file(fd, &cub3d_data))
		return (garbage_collector(&cub3d_data), -1); //change
	replace_spaces(&cub3d_data);
	printf("MAP AFTER REPLACEMENT:\n");
	print_map(&cub3d_data);
	printf("x:%f, y:%f\n", cub3d_data.player->x_pos, cub3d_data.player->y_pos);
	printf("orientation: %d, angle: %f\n", cub3d_data.player->orientation, cub3d_data.player->angle);
	if(!initiate_cub3d(&cub3d_data, &cast_data))
		garbage_collector(&cub3d_data);
	init_minimap(&cub3d_data, &minimap);
	cub3d_data.minimap = &minimap;
	draw_minimap(&cub3d_data); //change
	mlx_key_hook(cub3d_data.window, &esc_keyfunc, (void *)cub3d_data.window);
	mlx_loop_hook(cub3d_data.window, (void (*)(void *))gen_hooks, &cub3d_data);
	mlx_loop(cub3d_data.window);
	garbage_collector(&cub3d_data);//change
	return (0);
}
