/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:42:21 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/18 14:47:55 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files_bonus/cub3d_bonus.h"
#include "../header_files_bonus/cub3d_minimap_bonus.h"
#include "../header_files_bonus/cub3d_raycasting_bonus.h"

void	linear_move_hook(keys_t key, t_cub3d *cub3d)
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
	if (cub3d->player->mini_player)
		move_miniplayer(cub3d->player);
}

void	rotation_hook(keys_t key, t_cub3d *cub3d)
{
	if (key == MLX_KEY_LEFT)
		cub3d->player->angle = reset_circle(cub3d->player->angle - TURN_SPEED);
	if (key == MLX_KEY_RIGHT)
		cub3d->player->angle = reset_circle(cub3d->player->angle + TURN_SPEED);
	if (cub3d->player->mini_player)
		draw_player(cub3d->player->mini_player, cub3d->player->angle);
}

void	my_mouse_hook(t_cub3d *cub3d)
{
	int	mouse_x;
	int	temp;

	mlx_get_mouse_pos(cub3d->window, &mouse_x, &temp);
	temp = mouse_x - cub3d->prev_mouse_x;
	if (temp == 0)
		return ;
	if (temp < 0)
		cub3d->player->angle = \
			reset_circle(cub3d->player->angle - TURN_SPEED * abs(temp) / 10);
	else if (temp > 0)
		cub3d->player->angle = \
			reset_circle(cub3d->player->angle + TURN_SPEED * abs(temp) / 10);
	if (mouse_x > WIDTH || mouse_x < 0)
	{
		mlx_set_mouse_pos(cub3d->window, WIDTH / 2, HEIGHT / 2);
		cub3d->prev_mouse_x = WIDTH / 2;
	}
	else
		cub3d->prev_mouse_x = mouse_x;
	if (cub3d->player->mini_player)
		draw_player(cub3d->player->mini_player, cub3d->player->angle);
}
