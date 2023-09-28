/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:16:45 by crepou            #+#    #+#             */
/*   Updated: 2023/09/28 11:13:18 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

/*getting the line with the colors and save each inside a t_color struct*/
int	get_color(char *line, t_color *color)
{
	char	**colors;

	colors = ft_split(line, ',');
	if (!colors)
		return (printf("Error!\n Problem during saving color.\n"), FALSE);
	if (!colors[0] || !is_number(colors[0]))
		return (free_after_split(colors), FALSE);
	color->red = ft_atoi(colors[0]);
	if (!colors[1] || !is_number(colors[1]))
		return (free_after_split(colors), FALSE);
	color->green = ft_atoi(colors[1]);
	if (!colors[2] || !is_number(colors[2]))
		return (free_after_split(colors), FALSE);
	color->blue = ft_atoi(colors[2]);
	free_after_split(colors);
	return (TRUE);
}

/* It process and saves the info of the map*/
int	save_information(t_info *map_info, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		map_info->north_texture = get_info(line, 3, -1);
	else if (!ft_strncmp(line, "SO ", 3))
		map_info->south_texture = get_info(line, 3, -1);
	else if (!ft_strncmp(line, "EA ", 3))
		map_info->east_texture = get_info(line, 3, -1);
	else if (!ft_strncmp(line, "WE ", 3))
		map_info->west_texture = get_info(line, 3, -1);
	else if (!ft_strncmp(line, "F ", 2))
	{
		if (!get_color(get_info(line, 2, -1), &map_info->floor_color))
			return (printf("This is not a correct color!\n"), FALSE);
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		if (!get_color(get_info(line, 2, -1), &map_info->ceiling_color))
			return (printf("This is not a correct color!\n"), FALSE);
	}
	else
		return (printf("Error!\nThe line: %s is not recognised as information\n", \
			line), FALSE);
	if (files_exist(map_info))
		return (TRUE);
	return (FALSE);
}
