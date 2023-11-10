/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:06:00 by crepou            #+#    #+#             */
/*   Updated: 2023/11/10 15:44:30 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files_bonus/cub3d_bonus.h"

int	init_list(t_line **tail, t_line **head, char *curr_line)
{
	if (!curr_line)
		return (print("Error!\nThere is not map to parse!\n"), FALSE);
	*tail = (t_line *)malloc(sizeof(t_line));
	if (!(*tail))
		return (print("Error!\nMap allocation problem!\n"), FALSE);
	(*tail)->ln = curr_line;
	(*tail)->width = ft_strlen(curr_line);
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
	if (!(*cub3d_info)->map)
		return (print("Error!\n Map allocation problem\n"));
	while (y < (*cub3d_info)->height)
	{
		(*cub3d_info)->map[y] = (char *) \
			malloc(sizeof(char) * ((*cub3d_info)->width + 1));
		if (!(*cub3d_info)->map[y])
			return (print("Error!\n Map allocation problem\n"));
		y++;
	}
}
