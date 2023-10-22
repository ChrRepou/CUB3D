/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:07:50 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/22 20:56:07 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"
#include "../header_files/cub3d_minimap.h"



void	esc_keyfunc(mlx_key_data_t keydata, void *param)
{
	mlx_t	*window;

	window = (mlx_t *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(window);
	return ;
}

static void	move_miniplayer(t_player *player)
{

	player->mini_player->instances[0].x = \
		(int)round((player->x_pos - 0.5) * player->mini_player->height);
	player->mini_player->instances[0].y = \
		(int)round((player->y_pos - 0.5) * player->mini_player->height);
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
}

static void	rotation_hook(keys_t key, t_cub3d *cub3d_data)
{
	if (key == MLX_KEY_LEFT)
	{
		if (cub3d_data->player->angle <= 0)
			cub3d_data->player->angle = 359;
		else
			cub3d_data->player->angle--;
	}
	if (key == MLX_KEY_RIGHT)
	{
		if (cub3d_data->player->angle >= 360)
			cub3d_data->player->angle = 1;
		else
			cub3d_data->player->angle++;
	}
	if (cub3d_data->player->mini_player)
		draw_player(cub3d_data->player->mini_player, cub3d_data->player->angle);
}

void	generic_hooks(t_cub3d	*cub3d_data)
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
