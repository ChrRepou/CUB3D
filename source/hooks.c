/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:07:50 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/09 14:39:33 by tmarts           ###   ########.fr       */
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

static int	get_tile_size(map_w, map_h)
{
	if (MINI_W / map_w > MINI_H / map_h)
		return (MINI_H / map_h);
	else
		return (MINI_W / map_w);
}

static void move_miniplayer(t_cub3d *cub3d_data)
{
	int tile_size;
	
	tile_size = get_tile_size(cub3d_data->width, cub3d_data->width);
	cub3d_data->player->mini_player->instances[0].x = (cub3d_data->player->x_position -0.5) * tile_size;
	cub3d_data->player->mini_player->instances[0].y = (cub3d_data->player->y_position - 0.5) * tile_size;
}

static void	linear_move_hook(keys_t key, t_cub3d *cub3d_data)
{
	if (key == MLX_KEY_W)
	{
		// printf("Ypos pos: %f", cub3d_data->player->y_position);
		if (cub3d_data->map[(int)(cub3d_data->player->y_position - 0.2)][(int)cub3d_data->player->x_position] != '1')
			cub3d_data->player->y_position -= 0.2;
	}
	if (key == MLX_KEY_D)
	{
		if (cub3d_data->map[(int)cub3d_data->player->y_position][(int)(cub3d_data->player->x_position + 0.2)] != '1')
			 cub3d_data->player->x_position += 0.2;
	}
		//move right
	if (key == MLX_KEY_A)
	{
		if (cub3d_data->map[(int)cub3d_data->player->y_position][(int)(cub3d_data->player->x_position - 0.2)] != '1')
			 cub3d_data->player->x_position -= 0.2;
	}
	if (key == MLX_KEY_S)
	{
		// printf("Ypos: %f",  cub3d_data->player->y_position);
		if (cub3d_data->map[(int)(cub3d_data->player->y_position + 0.2)][(int)cub3d_data->player->x_position] != '1')
			cub3d_data->player->y_position += 0.2;
	}

}

// static void	rotation_hook(keys_t key, data_needed_for_calcualtions)
// {
// 	if (key == MLX_KEY_LEFT)
// 		//look left
// 	if (key == MLX_KEY_RIGHT)
// 		//look right
// 	// draw all again
// }

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
// 	if (mlx_is_key_down(s_map->window, MLX_KEY_LEFT))
// 		rotation_hook(MLX_KEY_LEFT, s_map);
// 	if (mlx_is_key_down(s_map->window, MLX_KEY_RIGHT))
// 		rotation_hook(MLX_KEY_RIGHT, s_map);
	// move_player(cub3d_data);
	move_miniplayer(cub3d_data);
	return ;
}
