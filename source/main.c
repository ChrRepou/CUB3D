/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:46 by crepou            #+#    #+#             */
/*   Updated: 2023/11/18 17:16:59 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d_raycasting.h"
#include "../header_files/utils.h"

/* to check for leaks add to main:
atexit(leaks); */
void	leaks( void )
{
	system("leaks cub3d");
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_cub3d		cub3d_data;
	t_caster	cast_data;

	atexit(leaks);
	fd = is_input_valid(argc, argv);
	if (!fd)
		return (-1);
	if (!read_file(fd, &cub3d_data))
		return (garbage_collector(&cub3d_data), EXIT_FAILURE);
	replace_spaces(&cub3d_data);
	if (!initiate_cub3d(&cub3d_data, &cast_data))
		return (garbage_collector(&cub3d_data), EXIT_FAILURE);
	mlx_key_hook(cub3d_data.window, &esc_keyfunc, (void *)cub3d_data.window);
	mlx_loop_hook(cub3d_data.window, (void (*)(void *))gen_hooks, &cub3d_data);
	mlx_loop(cub3d_data.window);
	garbage_collector(&cub3d_data);
	return (0);
}
