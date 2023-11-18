/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:07:50 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/18 14:37:51 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"
#include "../header_files/cub3d_raycasting.h"

void	esc_keyfunc(mlx_key_data_t keydata, void *param)
{
	mlx_t	*window;

	window = (mlx_t *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(window);
	return ;
}

static void	linear_move_hook(keys_t key, t_cub3d *cub3d)
{
	if (key == MLX_KEY_W)
		move_forward(cub3d->player, cub3d->map, \
		cub3d->player->x_pos, cub3d->player->y_pos);
	if (key == MLX_KEY_D)
		move_right(cub3d->player, cub3d->map, \
		cub3d->player->x_pos, cub3d->player->y_pos);
	if (key == MLX_KEY_A)
		move_left(cub3d->player, cub3d->map, \
		cub3d->player->x_pos, cub3d->player->y_pos);
	if (key == MLX_KEY_S)
		move_backward(cub3d->player, cub3d->map, \
		cub3d->player->x_pos, cub3d->player->y_pos);
}

static void	rotation_hook(keys_t key, t_cub3d *cub3d)
{
	if (key == MLX_KEY_LEFT)
		cub3d->player->angle = reset_circle(cub3d->player->angle - TURN_SPEED);
	if (key == MLX_KEY_RIGHT)
		cub3d->player->angle = reset_circle(cub3d->player->angle + TURN_SPEED);
}

void	gen_hooks(t_cub3d	*cub3d)
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
	draw_raycast_image(cub3d);
	return ;
}
