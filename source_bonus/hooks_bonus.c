/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:07:50 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/15 16:41:38 by tmarts           ###   ########.fr       */
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
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(cub3d->window);
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		change_door_status(cub3d);
	return ;
}

static void	linear_move_hook(keys_t key, t_cub3d *cub3d_data)
{
	if (key == MLX_KEY_W)
		move_forward(cub3d_data->player, cub3d_data->map, \
		cub3d_data->player->x_pos, cub3d_data->player->y_pos);
	if (key == MLX_KEY_D)
		move_right(cub3d_data->player, cub3d_data->map, \
		cub3d_data->player->x_pos, cub3d_data->player->y_pos);
	if (key == MLX_KEY_A)
		move_left(cub3d_data->player, cub3d_data->map, \
		cub3d_data->player->x_pos, cub3d_data->player->y_pos);
	if (key == MLX_KEY_S)
		move_backward(cub3d_data->player, cub3d_data->map, \
		cub3d_data->player->x_pos, cub3d_data->player->y_pos);
	if (cub3d_data->player->mini_player)
		move_miniplayer(cub3d_data->player);
	draw_raycast_image(cub3d_data);
}

static void	rotation_hook(keys_t key, t_cub3d *cub3d_data)
{
	if (key == MLX_KEY_LEFT)
	{
		if (cub3d_data->player->angle <= 0)
			cub3d_data->player->angle = cub3d_data->player->angle + 2 * M_PI;
		cub3d_data->player->angle -= TURN_SPEED;
	}
	if (key == MLX_KEY_RIGHT)
	{
		if (cub3d_data->player->angle >= 2 * M_PI)
			cub3d_data->player->angle = cub3d_data->player->angle - 2 * M_PI;
		cub3d_data->player->angle += TURN_SPEED;
	}
	if (cub3d_data->player->mini_player)
		draw_player(cub3d_data->player->mini_player, cub3d_data->player->angle);
	draw_raycast_image(cub3d_data);
}

void	gen_hooks(t_cub3d	*cub3d_data)
{
	if (mlx_is_key_down(cub3d_data->window, MLX_KEY_W))
		linear_move_hook(MLX_KEY_W, cub3d_data);
	if (mlx_is_key_down(cub3d_data->window, MLX_KEY_D))
		linear_move_hook(MLX_KEY_D, cub3d_data);
	if (mlx_is_key_down(cub3d_data->window, MLX_KEY_A))
		linear_move_hook(MLX_KEY_A, cub3d_data);
	if (mlx_is_key_down(cub3d_data->window, MLX_KEY_S))
		linear_move_hook(MLX_KEY_S, cub3d_data);
	if (mlx_is_key_down(cub3d_data->window, MLX_KEY_LEFT))
		rotation_hook(MLX_KEY_LEFT, cub3d_data);
	if (mlx_is_key_down(cub3d_data->window, MLX_KEY_RIGHT))
		rotation_hook(MLX_KEY_RIGHT, cub3d_data);
	return ;
}
