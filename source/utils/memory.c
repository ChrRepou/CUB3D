/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2023/11/06 12:59:19 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

/* It frees the memory after using function ft_split*/
void	free_after_split(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

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

void	free_map_info(t_cub3d *map_info)
{
	char	**map;
	int		i;

	map = map_info->map;
	i = 0;
	while (i < map_info->height)
	{
		free(map[i]);
		i++;
	}
	free(map);
	free(map_info->player);
	free(map_info->info->north_texture);
	free(map_info->info->east_texture);
	free(map_info->info->south_texture);
	free(map_info->info->west_texture);
	free(map_info->info);
	free(map_info);
}

void	delete_images(t_cub3d *cub3d_info) //change
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
		// if (cub3d_info->player->mini_player && cub3d_info->window) //its the pointer to img_player, so will cause double free
		// 	mlx_delete_image(cub3d_info->window, \
		// 					cub3d_info->player->mini_player);
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
	free_player(cub3d_info);
	free_map(cub3d_info);
	free_info(cub3d_info);
	if (cub3d_info->window)
		mlx_terminate(cub3d_info->window);
}

