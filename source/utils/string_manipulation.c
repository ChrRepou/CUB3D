/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:58:23 by crepou            #+#    #+#             */
/*   Updated: 2023/11/18 20:49:54 by crepou           ###   ########.fr       */
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
		while (line[end_index] != '\n' && line[end_index] != '\0')
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
	if (cub3d_info->player != NULL)
		return (FALSE);
	cub3d_info->player = (t_player *)malloc(sizeof(t_player));
	if (!cub3d_info->player)
		return (print("Error!\n Player allocation problem\n"), FALSE);
	cub3d_info->player->x_pos = x + 0.5;
	cub3d_info->player->y_pos = y + 0.5;
	if (c == 'N')
		cub3d_info->player->orientation = N;
	else if (c == 'S')
		cub3d_info->player->orientation = S;
	else if (c == 'E')
		cub3d_info->player->orientation = E;
	else
		cub3d_info->player->orientation = W;
	cub3d_info->player->angle = get_angle(cub3d_info->player->orientation);
	return (TRUE);
}

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

int	has_duplicates(t_info *map_info, char *line)
{
	if (!ft_strncmp(line, "NO ", 3) && map_info->north_texture != NULL)
		return (TRUE);
	if (!ft_strncmp(line, "SO ", 3) && map_info->south_texture != NULL)
		return (TRUE);
	if (!ft_strncmp(line, "EA ", 3) && map_info->east_texture != NULL)
		return (TRUE);
	if (!ft_strncmp(line, "WE ", 3) && map_info->west_texture != NULL)
		return (TRUE);
	if (!ft_strncmp(line, "F ", 2) && map_info->has_floor)
		return (TRUE);
	if (!ft_strncmp(line, "C ", 2) && map_info->has_celing)
		return (TRUE);
	return (FALSE);
}
