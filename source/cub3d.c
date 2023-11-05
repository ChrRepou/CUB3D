/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:24:29 by crepou            #+#    #+#             */
/*   Updated: 2023/11/05 22:29:29 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"
#include "../header_files/cub3d_raycasting.h"

void	init_struct(t_cub3d *cub3d_data) //change
{
	cub3d_data->minimap = NULL;
	cub3d_data->east_img = NULL;
	cub3d_data->north_img = NULL;
	cub3d_data->west_img = NULL;
	cub3d_data->south_img = NULL;
	cub3d_data->img = NULL;
	cub3d_data->window = NULL;
	cub3d_data->player = NULL;
	cub3d_data->raycaster = NULL;
	cub3d_data->map = NULL;
	cub3d_data->info = NULL;
}

int	initiate_cub3d(t_cub3d *cub3d_data, t_caster *cast_data)
{
	cub3d_data->player->mini_player = NULL;
	cub3d_data->raycaster = cast_data;
	if (initiate_mlx(cub3d_data) != 0)
		return (0); //change
	initiate_casting(cub3d_data->raycaster);
	draw_raycast_image(cub3d_data);
	return (1);
}
