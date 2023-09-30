/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:07:50 by tmarts            #+#    #+#             */
/*   Updated: 2023/09/30 18:51:53 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	esc_keyfunc(mlx_key_data_t keydata, void *param)
{
	mlx_t	*window;

	window = (mlx_t *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(window);
		return ;
	}
}

// static void	linear_move_hook(keys_t key, data_needed_for_calculations)
// {
// 	if (key == MLX_KEY_W)
// 		//move forward
// 	if (key == MLX_KEY_D)
// 		//move right
// 	if (key == MLX_KEY_A)
// 		//move left
// 	if (key == MLX_KEY_S)
// 		//move back

// 	// draw again
// }

// static void	rotation_hook(keys_t key, data_needed_for_calcualtions)
// {
// 	if (key == MLX_KEY_LEFT)
// 		//look left
// 	if (key == MLX_KEY_RIGHT)
// 		//look right
// 	// draw all again
// }

// void	generic_hooks(pointer_to_data_needed_for_calcualtions)
// {
// 	if (mlx_is_key_down(s_map->window, MLX_KEY_W))
// 		linear_move_hook(MLX_KEY_W, s_map);
// 	if (mlx_is_key_down(s_map->window, MLX_KEY_D))
// 		linear_move_hook(MLX_KEY_D, s_map);
// 	if (mlx_is_key_down(s_map->window, MLX_KEY_A))
// 		linear_move_hook(MLX_KEY_A, s_map);
// 	if (mlx_is_key_down(s_map->window, MLX_KEY_S))
// 		linear_move_hook(MLX_KEY_S, s_map);
// 	if (mlx_is_key_down(s_map->window, MLX_KEY_LEFT))
// 		rotation_hook(MLX_KEY_LEFT, s_map);
// 	if (mlx_is_key_down(s_map->window, MLX_KEY_RIGHT))
// 		rotation_hook(MLX_KEY_RIGHT, s_map);
// 	return ;
// }
