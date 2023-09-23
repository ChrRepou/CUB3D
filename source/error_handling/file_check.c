/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:18:03 by crepou            #+#    #+#             */
/*   Updated: 2023/09/23 17:08:54 by crepou           ###   ########.fr       */
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

int	read_file(int fd)
{
	char	*curr_line;
	int		first_line;
	int		map_parsing_start;
	t_info	map_info;

	first_line = TRUE;
	map_parsing_start = FALSE;
	if (is_empty_file(&curr_line, fd))
		return (FALSE);
	printf("line: %s is empty: %i\n", curr_line, ft_strncmp(curr_line, "\n", 1));
	if (!is_info(curr_line))
	{
		free(curr_line);
		return (FALSE);
	}
	save_information(&map_info, curr_line);
	free(curr_line);
	return (TRUE);
}
