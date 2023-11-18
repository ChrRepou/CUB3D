/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:22:19 by crepou            #+#    #+#             */
/*   Updated: 2023/11/18 20:43:28 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

/* 
The function returns true if the input is a number 
(doesn't contain special characters or letters)
*/
int	is_number(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*Checks if the line is an information line*/

int	is_info(char *line)
{
	if (!ft_strncmp(line, "\n", 1) || !ft_strncmp(line, "NO ", 3) || \
		!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "WE ", 3) || \
		!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "F ", 2) || \
		!ft_strncmp(line, "C ", 2))
		return (TRUE);
	return (FALSE);
}

int	has_all_info(t_cub3d *cub3d_info)
{
	t_info	*info;

	info = cub3d_info->info;
	if (!info->east_texture || !info->north_texture || !info->south_texture \
		|| !info->west_texture || info->has_celing == 0 || info->has_floor == 0)
		return (FALSE);
	return (TRUE);
}

int	valid_info(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\n')
		return (FALSE);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 32 \
			&& line[i] != '\n' && line[i] != 'S' && \
			line[i] != 'N' && line[i] != 'E' \
			&& line[i] != 'W')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	save_textures(t_info *map_info, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		map_info->north_texture = get_info(line, 3, -1);
	else if (!ft_strncmp(line, "SO ", 3))
		map_info->south_texture = get_info(line, 3, -1);
	else if (!ft_strncmp(line, "EA ", 3))
		map_info->east_texture = get_info(line, 3, -1);
	else if (!ft_strncmp(line, "WE ", 3))
		map_info->west_texture = get_info(line, 3, -1);
}
