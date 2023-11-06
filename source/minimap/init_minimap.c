/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:53:49 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/06 16:46:00 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

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

static int	init_player(t_cub3d *cub3d_data, t_minimap *minimap)
{
	minimap->img_player = \
		mlx_new_image(cub3d_data->window, minimap->tile_h, minimap->tile_h);
	cub3d_data->player->mini_player = minimap->img_player; //adding pointer to the main struct
	if (!minimap->img_player)
	{
		printf("error creating the player image\n");
		return (1);
	}
	draw_player(minimap->img_player, cub3d_data->player->angle);
	if (mlx_image_to_window(cub3d_data->window, minimap->img_player, \
	(int)round((cub3d_data->player->x_pos - 0.5) * minimap->tile_h), \
	(int)round((cub3d_data->player->y_pos - 0.5) * minimap->tile_h)) < 0)
	{
		printf("error displaying player image\n");
		return (1);
	}
	return (0);
}

int	init_minimap(t_cub3d *cub3d_data, t_minimap *minimap)
{
	cub3d_data->minimap = minimap;
	minimap->tile_h = get_tile_size(cub3d_data->width, cub3d_data->height);
	if (minimap->tile_h < 1)
	{
		cub3d_data->player->mini_player = NULL;
		return (minimap_not_displayed(minimap), 0);
	}
	minimap->img_mini = mlx_new_image(cub3d_data->window, MINI_W, MINI_H);
	if (!minimap->img_mini)
	{
		printf("error creating the minimap image\n");
		garbage_collector(cub3d_data);// free everything //change
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(cub3d_data->window, minimap->img_mini, 0, 0) < 0)
	{
		printf("error displaying the minimap image\n");
		garbage_collector(cub3d_data);//free everything;
		exit(EXIT_FAILURE);
	}
	draw_minimap(cub3d_data);
	if (init_player(cub3d_data, minimap) != 0)
	{
		garbage_collector(cub3d_data);//free everything
		exit(EXIT_FAILURE);
	}
	return (0);
}
