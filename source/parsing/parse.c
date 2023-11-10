/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:16:45 by crepou            #+#    #+#             */
/*   Updated: 2023/11/10 17:38:06 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

/*getting the line with the colors and save each inside a t_color struct*/
int	get_color(char *line, t_color *color, uint32_t *pixel_color)
{
	char	**colors;

	colors = ft_split(line, ',');
	if (!colors)
		return (print("Error!\n Problem during saving color.\n"), FALSE);
	if (!colors[0] || !is_number(colors[0]))
		return (free(line), free_after_split(colors), FALSE);
	color->red = ft_atoi(colors[0]);
	if (!colors[1] || !is_number(colors[1]))
		return (free(line), free_after_split(colors), FALSE);
	color->green = ft_atoi(colors[1]);
	if (!colors[2] || !is_number(colors[2]))
		return (free(line), free_after_split(colors), FALSE);
	color->blue = ft_atoi(colors[2]);
	free_after_split(colors);
	*pixel_color = rgb_to_color(*color);
	free(line);
	return (TRUE);
}

/* It process and saves the info of the map*/
int	save_information(t_info *map_info, char *line)
{
	if (!ft_strncmp(line, "\n", 1))
		return (free(line), TRUE);
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
		if (!get_color(get_info(line, 2, -1), \
			&map_info->floor_rgb, &map_info->floor_color))
			return (print("This is not a correct color!\n"), FALSE);
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		if (!get_color(get_info(line, 2, -1), \
			&map_info->ceiling_rgb, &map_info->celing_color))
			return (print("This is not a correct color!\n"), FALSE);
	}
	if (files_exist(map_info))
		return (free(line), TRUE);
	return (FALSE);
}

/* 
saves a line into the map array and returns TRUE in success
otherwise it returns FALSE with an error message
*/
int	save_line(char *line, t_cub3d **cub3d_info, int index)
{
	int		i;

	if (!(*cub3d_info)->map[index])
		return (print("Problem during allocation!\n"), FALSE);
	i = -1;
	while (++i < (*cub3d_info)->width)
	{
		if (i > (int)ft_strlen(line) || !line[i] || line[i] == 10)
			(*cub3d_info)->map[index][i] = 32;
		else if (line[i] == 32 || line[i] == '1' || line[i] == '0' \
			|| is_orientation(line[i], (*cub3d_info), i, index))
			(*cub3d_info)->map[index][i] = line[i];
		else
			return (print("Error! This is not a valid map!\n"), FALSE);
	}
	(*cub3d_info)->map[index][i] = '\0';
	return (TRUE);
}

/*
saves the whole map in an array and returns TRUE
otherwise returns FALSE
*/
int	create_map_array(t_line *head, t_cub3d *cub3d_info)
{
	t_line	*list;
	int		i;

	list = head;
	cub3d_info->width = get_width(head);
	cub3d_info->index = 0;
	init_map(&cub3d_info);
	i = 0;
	while (list)
	{
		if (list->width < cub3d_info->width)
			list->ln = create_expanded_line(cub3d_info, list);
		if (!save_line(list->ln, &cub3d_info, i))
			return (FALSE);
		list = list->next;
		i++;
	}
	return (TRUE);
}

int	save_map(t_cub3d *cub3d_info, char *curr_line, int fd)
{
	t_line	*map_lines;
	t_line	*tail;
	t_line	*head;

	head = NULL;
	tail = NULL;
	if (!init_list(&tail, &head, curr_line))
		return (FALSE);
	cub3d_info->height = 1;
	while (!is_empty_file(&curr_line, fd))
	{
		map_lines = (t_line *)malloc(sizeof(t_line));
		if (!map_lines)
			return (free_map_lines(head), printf("Error!\n"), FALSE);
		create_map_line(map_lines, curr_line);
		tail->next = map_lines;
		tail = tail->next;
		cub3d_info->height++;
	}
	if (!create_map_array(head, cub3d_info))
		return (free_map_lines(head), FALSE);
	if (!map_is_valid(cub3d_info))
		return (free_map_lines(head), FALSE);
	return (free_map_lines(head), TRUE);
}
