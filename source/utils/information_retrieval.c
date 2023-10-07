/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information_retrieval.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:05:34 by crepou            #+#    #+#             */
/*   Updated: 2023/10/07 13:24:25 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

/* it gets the width of a line */
int	get_width(char *line)
{
	int	width;

	width = 0;
	while (line[width] && line[width] != '\n')
		width++;
	return (width);
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
	printf("HEIGHT: %d | WIDTH: %d\n", height, width);
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
