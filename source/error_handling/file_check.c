/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:18:03 by crepou            #+#    #+#             */
/*   Updated: 2023/10/21 20:55:03 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

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
/*checks if a file is empty before parsing*/

int	is_empty_file(char **line, int fd)
{
	*line = get_next_line(fd);
	if (!(*line))
		return (TRUE);
	return (FALSE);
}

/*Initialize map info*/
void	init_map_info(t_info *map_info)
{
	map_info->east_texture = NULL;
	map_info->north_texture = NULL;
	map_info->west_texture = NULL;
	map_info->south_texture = NULL;
}

/* checks if a file is empty or not and then saves the information and the map*/
int	read_file(int fd, t_cub3d *cub3d_info)
{
	char	*curr_line;
	int		first_line;
	int		map_parsing_start;

	first_line = TRUE;
	map_parsing_start = FALSE;
	cub3d_info->info = (t_info *)malloc(sizeof(t_info));
	init_map_info(cub3d_info->info);
	while (!is_empty_file(&curr_line, fd))
	{
		if (first_line)
			first_line = FALSE;
		if (!is_info(curr_line))
			break ;
		if (!save_information(cub3d_info->info, curr_line))
			return (free(curr_line), FALSE);
	}
	if (first_line)
		return (FALSE);
	cub3d_info->map = NULL;
	map_parsing_start = TRUE;
	if (!save_map(cub3d_info, curr_line, fd))
		return (FALSE);
	return (TRUE);
}

/* checks if the texture files exist*/
int	files_exist(t_info *map_info)
{
	int	fd;

	fd = open(map_info->north_texture, O_RDONLY);
	if (fd == -1 && map_info->north_texture)
		return (print_s("Error!\nThe file: %s doesn't exist!\n", \
			map_info->north_texture), FALSE);
	close(fd);
	fd = open(map_info->south_texture, O_RDONLY);
	if (fd == -1 && map_info->south_texture)
		return (print_s("Error!\nThe file: %s doesn't exist!\n", \
			map_info->south_texture), FALSE);
	close(fd);
	fd = open(map_info->east_texture, O_RDONLY);
	if (fd == -1 && map_info->east_texture)
		return (print_s("Error!\nThe file: %s doesn't exist!\n", \
			map_info->east_texture), FALSE);
	close(fd);
	fd = open(map_info->west_texture, O_RDONLY);
	if (fd == -1 && map_info->west_texture)
		return (print_s("Error!\nThe file: %s doesn't exist!\n", \
			map_info->west_texture), FALSE);
	close(fd);
	return (TRUE);
}
