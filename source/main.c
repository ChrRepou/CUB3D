/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:46 by crepou            #+#    #+#             */
/*   Updated: 2023/10/06 20:00:35 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"
#include "../header_files/cub3d_minimap.h"


int	main(int argc, char *argv[])
{
	int			fd;
	t_cub3d		cub3d_data;
	t_minimap	minimap;

	fd = is_input_valid(argc, argv);
	if (!fd)
		return (-1);
	read_file(fd, &cub3d_data);
	cub3d_data.height++;
	printf("%d\n", cub3d_data.height);
	printf("%d\n", cub3d_data.width);
	int i = 0;
	int j = 0;
	while (i < cub3d_data.height)
	{
		while (j < cub3d_data.width)
		{
			printf("%d  ", cub3d_data.map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	cub3d_data.player->x_position = 26;
	cub3d_data.player->y_position = 11;
	printf("Player map coordinates %d %d\n", cub3d_data.player->x_position, cub3d_data.player->y_position);
	initiate_window(&cub3d_data);
	init_minimap(&cub3d_data, &minimap);
	// ft_memset(cub3d_data.img->pixels, 255, cub3d_data.img->width * cub3d_data.img->height * sizeof(int32_t));
	draw_minimap(&cub3d_data, &minimap);
	mlx_key_hook(cub3d_data.window, &esc_keyfunc, (void *)cub3d_data.window);
	// mlx_loop_hook(cub3d_data.window, (void (*)(void *))generic_hooks, &cub3d_data);
	mlx_loop(cub3d_data.window);
	mlx_delete_image(cub3d_data.window, cub3d_data.img);
	mlx_terminate(cub3d_data.window);
	free(cub3d_data.map);
	return (0);
}



