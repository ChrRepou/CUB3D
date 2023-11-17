/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:24:29 by crepou            #+#    #+#             */
/*   Updated: 2023/11/17 19:44:14 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files_bonus/cub3d_bonus.h"
#include "../header_files_bonus/cub3d_raycasting_bonus.h"

void	init_struct(t_cub3d *cub3d_data)
{
	cub3d_data->minimap = NULL;
	cub3d_data->img = NULL;
	cub3d_data->window = NULL;
	cub3d_data->player = NULL;
	cub3d_data->raycaster = NULL;
	cub3d_data->map = NULL;
	cub3d_data->info = NULL;
}

static void	initiate_mouse(t_cub3d *cub3d_data)
{
	mlx_set_cursor_mode(cub3d_data->window, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(cub3d_data->window, WIDTH / 2, HEIGHT / 2);
	cub3d_data->prev_mouse_x = WIDTH / 2;
}

int	initiate_cub3d(t_cub3d *cub3d_data, t_caster *cast_data)
{
	cub3d_data->player->mini_player = NULL;
	cub3d_data->raycaster = cast_data;
	if (!initiate_mlx(cub3d_data))
		return (FALSE);
	if (!initiate_textures(cub3d_data))
		return (FALSE);
	if (!initiate_bonus_textures(cub3d_data->info))
		return (FALSE);
	initiate_casting(cub3d_data->raycaster);
	initiate_mouse(cub3d_data);
	draw_raycast_image(cub3d_data);
	return (TRUE);
}
