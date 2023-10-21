/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:06:00 by crepou            #+#    #+#             */
/*   Updated: 2023/10/21 20:25:45 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

int	init_list(t_line **tail, t_line **head, char *curr_line)
{
	if (!curr_line)
		return (print("Error!\n There is not map to parse\n"), FALSE);
	*tail = (t_line *)malloc(sizeof(t_line));
	if (!(*tail))
		return (print("Error!\n Map allocation problem\n"), FALSE);
	(*tail)->ln = curr_line;
	(*tail)->next = NULL;
	*head = *tail;
	return (TRUE);
}

void	init_map(t_cub3d **cub3d_info)
{
	int	y;

	y = 0;
	(*cub3d_info)->map = (char **) \
		malloc(sizeof(char *) * (*cub3d_info)->height);
	while (y < (*cub3d_info)->height)
	{
		(*cub3d_info)->map[y] = (char *) \
			malloc(sizeof(char) * ((*cub3d_info)->width + 1));
		y++;
	}
}
