/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:07:50 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/18 16:17:12 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files_bonus/cub3d_bonus.h"
#include "../header_files_bonus/cub3d_minimap_bonus.h"
#include "../header_files_bonus/cub3d_raycasting_bonus.h"

static void	change_door_status(t_cub3d *cub3d)
{
	double	front_x;
	double	front_y;

	front_x = cub3d->player->x_pos + cos(cub3d->player->angle) * 1.2;
	front_y = cub3d->player->y_pos + sin(cub3d->player->angle) * 1.2;
	if (cub3d->map[(int)front_y][(int)front_x] == '2' && \
		cub3d->map[(int)cub3d->player->y_pos][(int)cub3d->player->x_pos] != '2')
	{
		cub3d->map[(int)front_y][(int)front_x] = '3';
		draw_raycast_image(cub3d);
		return ;
	}
	if (cub3d->map[(int)front_y][(int)front_x] == '3' && \
		cub3d->map[(int)cub3d->player->y_pos][(int)cub3d->player->x_pos] != '3')
	{
		cub3d->map[(int)front_y][(int)front_x] = '2';
		draw_raycast_image(cub3d);
	}
}

void	keyfunc(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (mlx_is_key_down(cub3d->window, MLX_KEY_SPACE))
		change_door_status(cub3d);
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(cub3d->window);
	return ;
}

void	gen_hooks(t_cub3d *cub3d)
{
	if (mlx_is_key_down(cub3d->window, MLX_KEY_W))
		linear_move_hook(MLX_KEY_W, cub3d);
	if (mlx_is_key_down(cub3d->window, MLX_KEY_D))
		linear_move_hook(MLX_KEY_D, cub3d);
	if (mlx_is_key_down(cub3d->window, MLX_KEY_A))
		linear_move_hook(MLX_KEY_A, cub3d);
	if (mlx_is_key_down(cub3d->window, MLX_KEY_S))
		linear_move_hook(MLX_KEY_S, cub3d);
	if (mlx_is_key_down(cub3d->window, MLX_KEY_LEFT))
		rotation_hook(MLX_KEY_LEFT, cub3d);
	if (mlx_is_key_down(cub3d->window, MLX_KEY_RIGHT))
		rotation_hook(MLX_KEY_RIGHT, cub3d);
	my_mouse_hook(cub3d);
	draw_raycast_image(cub3d);
	return ;
}
