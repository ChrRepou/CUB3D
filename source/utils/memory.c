/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:11:32 by crepou            #+#    #+#             */
/*   Updated: 2023/10/23 18:53:16 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

/* It frees the memory after using function ft_split*/
void	free_after_split(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	if (array)
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
	// free(map_info);
}
