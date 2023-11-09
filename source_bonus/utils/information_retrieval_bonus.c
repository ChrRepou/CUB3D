/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information_retrieval_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:05:34 by crepou            #+#    #+#             */
/*   Updated: 2023/11/09 21:08:56 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files_bonus/cub3d_bonus.h"

/* it gets the width of a line */
int	get_width(t_line *head)
{
	int		width;
	int		max_width;
	char	*line;

	width = 0;
	max_width = 0;
	while (head)
	{
		line = head->ln;
		while (line[width] && line[width] != '\n')
			width++;
		if (max_width < width)
			max_width = width;
		width = 0;
		head = head->next;
	}
	return (max_width);
}

/* It prints a list */
void	print_list(t_line *head)
{
	int	i;

	i = 0;
	while (head)
	{
		printf("Line %d: %s\n", i, head->ln);
		i++;
		head = head->next;
	}
}

void	print_map(t_cub3d *cub3d_info)
{
	int		x;
	int		y;
	int		height;
	int		width;
	char	**map;

	x = 0;
	y = 0;
	map = cub3d_info->map;
	height = cub3d_info->height;
	width = cub3d_info->width;
	while (y < height)
	{
		while (x < width)
		{
			printf("%c", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
		x = 0;
	}
}

/*
arguments: a character from the map array
return value: 1 if its player, 0 if not
*/
int	is_player(char info)
{
	if (info == 'N' || info == 'E' || info == 'S' || info == 'W')
		return (1);
	return (0);
}
