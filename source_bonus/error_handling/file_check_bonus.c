/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:18:03 by crepou            #+#    #+#             */
/*   Updated: 2023/11/18 20:52:46 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files_bonus/cub3d_errors_bonus.h"
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
	map_info->closed_door = NULL;
	map_info->north = NULL;
	map_info->south = NULL;
	map_info->east = NULL;
	map_info->west = NULL;
	map_info->has_celing = 0;
	map_info->has_floor = 0;
}

int	extensions_correct(t_cub3d *cub3d_info)
{
	t_info	*info;

	info = cub3d_info->info;
	if (!check_extension(info->north_texture, ".png") || \
		!check_extension(info->east_texture, ".png") || \
		!check_extension(info->west_texture, ".png") || \
		!check_extension(info->south_texture, ".png"))
		return (FALSE);
	return (TRUE);
}

/* checks if a file is empty or not and then saves the information and the map*/
int	read_file(int fd, t_cub3d *cub3d_info)
{
	char	*curr_line;
	int		first_line;

	first_line = TRUE;
	init_struct(cub3d_info);
	cub3d_info->info = (t_info *)malloc(sizeof(t_info));
	if (!cub3d_info->info)
		return (print("Error!\n Allocation problem\n"), FALSE);
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
		return (print("Error! The file shouldn't be empty!\n"), FALSE);
	cub3d_info->map = NULL;
	if (!save_map(cub3d_info, curr_line, fd) || !extensions_correct(cub3d_info))
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
