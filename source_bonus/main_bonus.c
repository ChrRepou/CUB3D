/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:46 by crepou            #+#    #+#             */
/*   Updated: 2023/11/15 18:14:37 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files_bonus/cub3d_raycasting_bonus.h"
#include "../header_files_bonus/cub3d_minimap_bonus.h"
#include "../header_files_bonus/utils_bonus.h"

void	leaks( void )
{
	system("leaks cub3d_bonus");
}

void	mouse_rotation(double x_pos, double y_pos, void *param)
{
	t_cub3d			*cub3d;
	double			delta_x;
	// static double	previous_x;

	cub3d = (t_cub3d *)param;
	delta_x = x_pos - WIDTH / 2;
	// previous_x = x_pos;
	y_pos = 0;
	// if (delta_x < 0)
	// {
		if (cub3d->player->angle <= 0)
			cub3d->player->angle = cub3d->player->angle + 2 * M_PI;
		else if (cub3d->player->angle >= 2 * M_PI)
			cub3d->player->angle = cub3d->player->angle - 2 * M_PI;
		cub3d->player->angle += delta_x * cub3d->raycaster->ray_angle_step;
	// }
	// if (delta_x > 0)
	// {
	// 	if (cub3d->player->angle >= 2 * M_PI)
	// 		cub3d->player->angle = cub3d->player->angle - 2 * M_PI;
	// 	cub3d->player->angle += TURN_SPEED / 4;
	// }
	if (cub3d->player->mini_player)
		draw_player(cub3d->player->mini_player, cub3d->player->angle);
	draw_raycast_image(cub3d);
}


int	main(int argc, char *argv[])
{
	int			fd;
	t_cub3d		cub3d_data;
	t_caster	cast_data;
	t_minimap	minimap;

	// atexit(leaks);
	fd = is_input_valid(argc, argv);
	if (!fd)
		return (-1);
	if (!read_file(fd, &cub3d_data))
		return (garbage_collector(&cub3d_data), EXIT_FAILURE);
	replace_spaces(&cub3d_data);
	if (!initiate_cub3d(&cub3d_data, &cast_data))
		return (garbage_collector(&cub3d_data), EXIT_FAILURE);
	mlx_set_mouse_pos(cub3d_data.window, WIDTH / 2, HEIGHT / 2);
	if (!init_minimap(&cub3d_data, &minimap))
		return (garbage_collector(&cub3d_data), EXIT_FAILURE);
	mlx_key_hook(cub3d_data.window, &keyfunc, (void *)&cub3d_data);
	mlx_loop_hook(cub3d_data.window, (void (*)(void *))gen_hooks, &cub3d_data);
	mlx_cursor_hook(cub3d_data.window, mouse_rotation, &cub3d_data);
	mlx_loop(cub3d_data.window);
	garbage_collector(&cub3d_data);
	return (0);
}

//add door and sprite to the texture pointers and load them in the beginning 
//- when getting texture check if N or E wall is door/sprite, if S-or W wall 
//is door/sprite
// for partner check that door is between two walls 