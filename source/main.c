/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:46 by crepou            #+#    #+#             */
/*   Updated: 2023/10/20 21:57:11 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"
#include "../header_files/cub3d_minimap.h"

void	free_data(t_cub3d *cub3d_data)
{
	int	i;

	i = 0;
	if (cub3d_data->map != NULL)
	{
		while (i < cub3d_data->height)
		{
			free(cub3d_data->map[i]);
			i++;
		}
		free(cub3d_data->map);
	}
	free(cub3d_data->player);
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_cub3d		cub3d_data;
	t_minimap	minimap;

	fd = is_input_valid(argc, argv);
	if (!fd)
		return (-1);
	if (!read_file(fd, &cub3d_data))
		return (-1);
	replace_spaces(&cub3d_data);
	printf("MAP AFTER REPLACEMENT:\n");
	print_map(&cub3d_data);
	cub3d_data.player->mini_player = NULL;
	cub3d_data.player->x_position += 0.5; // adding to place the player in the middle of the square
	cub3d_data.player->y_position += 0.5;
	printf("x:%f, y:%f\n", cub3d_data.player->x_position, cub3d_data.player->y_position);
	cub3d_data.player->angle = (double)cub3d_data.player->orientation;
	printf("orientation: %d, angle: %f\n", cub3d_data.player->orientation, cub3d_data.player->angle);
	initiate_window(&cub3d_data);
	init_minimap(&cub3d_data, &minimap);
	ft_memset(cub3d_data.img->pixels, 255, cub3d_data.img->width * cub3d_data.img->height * sizeof(int32_t));
	draw_minimap(&cub3d_data, &minimap);
	mlx_key_hook(cub3d_data.window, &esc_keyfunc, (void *)cub3d_data.window);
	mlx_loop_hook(cub3d_data.window, (void (*)(void *))generic_hooks, &cub3d_data);
	mlx_loop(cub3d_data.window);
	mlx_delete_image(cub3d_data.window, cub3d_data.img);
	mlx_terminate(cub3d_data.window);
	free_data(&cub3d_data);
	system("leaks cub3d");
	return (0);
}



