/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:11:32 by crepou            #+#    #+#             */
/*   Updated: 2023/11/06 14:26:29 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
/* Free every map_line we saved in the linked list */
void	free_map_lines(t_line *line)
{
	t_line	*head;

	head = line;
	while (head)
	{
		if (head->ln)
			free(head->ln);
		head = line->next;
		if (line)
			free(line);
		line = head;
	}
}

void	delete_images(t_cub3d *cub3d_info)
{
	if (cub3d_info->img)
		mlx_delete_image(cub3d_info->window, cub3d_info->img);
	if (cub3d_info->north_img)
		mlx_delete_image(cub3d_info->window, cub3d_info->north_img);
	if (cub3d_info->south_img)
		mlx_delete_image(cub3d_info->window, cub3d_info->south_img);
	if (cub3d_info->east_img)
		mlx_delete_image(cub3d_info->window, cub3d_info->east_img);
	if (cub3d_info->west_img)
		mlx_delete_image(cub3d_info->window, cub3d_info->west_img);
	if (cub3d_info->minimap)
	{
		if (cub3d_info->minimap->img_mini)
			mlx_delete_image(cub3d_info->window, cub3d_info->minimap->img_mini);
		if (cub3d_info->minimap->img_player)
			mlx_delete_image(cub3d_info->window, \
							cub3d_info->minimap->img_player);
	}
}

void	free_player(t_cub3d *cub3d_info)
{
	if (cub3d_info->player)
	{
		if (cub3d_info->player->mini_player && cub3d_info->window)
			mlx_delete_image(cub3d_info->window, \
							cub3d_info->player->mini_player);
		free(cub3d_info->player);
	}
}

void	free_map(t_cub3d *cub3d_info)
{
	char	**map;
	int		i;

	map = cub3d_info->map;
	if (!map)
		return ;
	i = 0;
	while (i < cub3d_info->height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	free_info(t_cub3d *cub3d_info)
{
	if (cub3d_info->info)
	{
		if (cub3d_info->info->north_texture)
			free(cub3d_info->info->north_texture);
		if (cub3d_info->info->south_texture)
			free(cub3d_info->info->south_texture);
		if (cub3d_info->info->east_texture)
			free(cub3d_info->info->east_texture);
		if (cub3d_info->info->west_texture)
			free(cub3d_info->info->west_texture);
		free(cub3d_info->info);
	}
}

//it checks for allocated memory and frees everything
void	garbage_collector(t_cub3d *cub3d_info)
{
	delete_images(cub3d_info);
	if (cub3d_info->player)
		free(cub3d_info->player);
	free_map(cub3d_info);
	free_info(cub3d_info);
	if (cub3d_info->window)
		mlx_terminate(cub3d_info->window);
}

