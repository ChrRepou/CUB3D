/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:46 by crepou            #+#    #+#             */
/*   Updated: 2023/09/27 21:05:20 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	main(int argc, char *argv[])
{
	int	fd;
	t_displ s_displ;

	fd = is_input_valid(argc, argv);
	if (!fd)
		return (-1);
	initiate_window(&s_displ);
	mlx_key_hook(s_displ.window, &esc_keyfunc, (void *)&s_displ);
	// mlx_loop_hook(s_displ.window, (void (*)(void *))generic_hooks, &s_displ);
	mlx_loop(s_displ.window);
	mlx_delete_image(s_displ.window, s_displ.img);
	mlx_terminate(s_displ.window);
	return (0);
}



