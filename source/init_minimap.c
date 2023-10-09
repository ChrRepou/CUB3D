/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:53:49 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/09 14:20:21 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"
#include "../header_files/cub3d_minimap.h"

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

void	draw_direction(mlx_image_t *img, int tile_h)
{
	int	orig;
	int	y;

	orig = tile_h / 2;
	y = orig;
	while (y > (tile_h / 6))
	{
		mlx_put_pixel(img, orig, y, PLAYER_COLOR);
		y--;
	}
}

static void	draw_player(mlx_image_t *img, int tile_h)
{
	int	x_px;
	int	y_px;
	int	x_start;
	int	end;

	x_px = tile_h / 2 - 2;
	y_px = tile_h / 2 - 2;
	end = tile_h / 2 + 3;
	x_start = x_px;
	while (y_px <= end)
	{
		mlx_put_pixel(img, x_px++, y_px, PLAYER_COLOR);
		if (x_px == end)
		{
			x_px = x_start;
			y_px++;
		}
	}
	// mlx_put_pixel(img, tile_h / 2, tile_h / 2, PLAYER_COLOR);
		// int	r;
	// int	orig;
	// int	x;
	// int	y;
	// int	h;

	// r = tile_h / 6;
	// orig = tile_h / 2;
	// x = -r;
	// while (x < r)
	// {
	// 	h = (int)sqrt(r * r - x * x);
	// 	y = -h;
	// 	while (y < h)
	// 	{
	// 		mlx_put_pixel(img, (x + orig), (y + orig), PLAYER_COLOR);
	// 		y++;
	// 	}
	// 	x++;
	// }
	draw_direction(img, tile_h);
}


int	init_minimap(t_cub3d *cub3d_data, t_minimap *minimap)
{
	minimap->tile_h = get_tile_size(cub3d_data->width, cub3d_data->height);
	if (minimap->tile_h < 1)
		return (minimap_not_displayed(minimap), 0);
	printf("%d\n", minimap->tile_h);
	minimap->img_mini = mlx_new_image(cub3d_data->window, MINI_W, MINI_H);
	if (!minimap->img_mini)
	{
		printf("error creating the minimap image\n");
		// free everything
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(cub3d_data->window, minimap->img_mini, 0, 0) < 0)
	{
		printf("error displaying the minimap image\n");
		//free everything;
		exit(EXIT_FAILURE);
	}
	minimap->img_player = mlx_new_image(cub3d_data->window, minimap->tile_h, minimap->tile_h);
	cub3d_data->player->mini_player = minimap->img_player;
	if (!minimap->img_player)
	{
		printf("error creating the player image\n");
		// free everything
		exit(EXIT_FAILURE);
	}
	// ft_memset(minimap->img_player->pixels, 200, minimap->img_player->width * minimap->img_player->height * sizeof(int32_t));
	draw_player(minimap->img_player, minimap->tile_h);
	if (mlx_image_to_window(cub3d_data->window, minimap->img_player, \
			(cub3d_data->player->x_position - 0.5) * minimap->tile_h, (cub3d_data->player->y_position - 0.5) * minimap->tile_h) < 0)
	{
		printf("error displaying player image\n");
		//free everything;
		exit(EXIT_FAILURE);
	}
	return (0);
}

