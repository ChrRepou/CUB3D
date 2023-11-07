/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:53:49 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/07 20:19:04 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
#include "../../header_files/cub3d_minimap.h"

/*Calculates and returns side length of one minimap tile*/
static int	get_tile_size(map_w, map_h)
{
	if (MINI_W / map_w > MINI_H / map_h)
		return (MINI_H / map_h);
	else
		return (MINI_W / map_w);
}

static void	minimap_not_displayed(t_minimap *minimap)
{
	printf("Thats a big map! Minimap will not be displayed.");
	minimap->img_mini = NULL;
	minimap->img_player = NULL;
	minimap->tile_h = 0;
}

/*Creates a player image on the minimap and places it to the start position*/
static int	init_player(t_cub3d *cub3d_data, t_minimap *minimap)
{
	minimap->img_player = \
		mlx_new_image(cub3d_data->window, minimap->tile_h, minimap->tile_h);
	cub3d_data->player->mini_player = minimap->img_player;
	if (!minimap->img_player)
	{
		printf("Error creating the player image\n");
		return (FALSE);
	}
	draw_player(minimap->img_player, cub3d_data->player->angle);
	if (mlx_image_to_window(cub3d_data->window, minimap->img_player, \
	(int)round((cub3d_data->player->x_pos - 0.5) * minimap->tile_h), \
	(int)round((cub3d_data->player->y_pos - 0.5) * minimap->tile_h)) < 0)
	{
		printf("Error displaying player image\n");
		return (FALSE);
	}
	return (TRUE);
}

int	init_minimap(t_cub3d *cub3d_data, t_minimap *minimap)
{
	cub3d_data->minimap = minimap;
	minimap->tile_h = get_tile_size(cub3d_data->width, cub3d_data->height);
	if (minimap->tile_h < 3)
		return (minimap_not_displayed(minimap), TRUE);
	minimap->img_mini = mlx_new_image(cub3d_data->window, MINI_W, MINI_H);
	if (!minimap->img_mini)
	{
		printf("Error creating the minimap image\n");
		return (FALSE);
	}
	if (mlx_image_to_window(cub3d_data->window, minimap->img_mini, 0, 0) < 0)
	{
		printf("error displaying the minimap image\n");
		return (FALSE);
	}
	draw_minimap(cub3d_data);
	if (!init_player(cub3d_data, minimap))
		return (FALSE);
	return (TRUE);
}
