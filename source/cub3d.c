/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:24:29 by crepou            #+#    #+#             */
/*   Updated: 2023/11/04 19:16:54 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"
#include "../header_files/cub3d_raycasting.h"

int	initiate_cub3d(t_cub3d *cub3d_data, t_caster *cast_data)
{
	cub3d_data->player->mini_player = NULL;
	cub3d_data->raycaster = cast_data;
	if (initiate_mlx(cub3d_data) != 0)
		return (1);
	initiate_casting(cub3d_data->raycaster);
	draw_raycast_image(cub3d_data);
	return (0);
}