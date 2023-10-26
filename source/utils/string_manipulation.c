/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:58:23 by crepou            #+#    #+#             */
/*   Updated: 2023/10/26 16:57:21 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
/*
returns the string contained in the line starting 
from index: start_index until index:end_index

if the end_index is 0 then it goes until the end of the string

implements malloc so it has to be free, it doesn't free the line
*/
char	*get_info(char *line, int start_index, int end_index)
{
	char	*new_line;
	int		i;

	if (end_index == -1)
	{
		end_index = start_index;
		while (line[end_index] != '\n')
			end_index++;
	}
	new_line = (char *)malloc(end_index - start_index + 1);
	if (!new_line)
		return (print("Error!\n Map allocation problem\n"), NULL);
	i = 0;
	while (start_index < end_index)
	{
		new_line[i] = line[start_index];
		i++;
		start_index++;
	}
	new_line[i] = '\0';
	return (new_line);
}

/* converts a character to a string */
char	*char_to_string(char c)
{
	char	*str;

	str = (char *)malloc(2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

/* 
check if a letter during the parsing of the map is an orientation one,
saves the info of the player and returns TRUE
otherwise it returns FALSE
*/
int	is_orientation(char c, t_cub3d *cub3d_info, int x, int y)
{
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (FALSE);
	cub3d_info->player = (t_player *)malloc(sizeof(t_player));
	if (!cub3d_info->player)
		return (print("Error!\n Player allocation problem\n"), FALSE);
	cub3d_info->player->x_pos = x;
	cub3d_info->player->y_pos = y;
	if (c == 'N')
		cub3d_info->player->orientation = N;
	else if (c == 'S')
		cub3d_info->player->orientation = S;
	else if (c == 'E')
		cub3d_info->player->orientation = E;
	else
		cub3d_info->player->orientation = W;
	return (TRUE);
}
