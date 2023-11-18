/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:01:25 by crepou            #+#    #+#             */
/*   Updated: 2023/11/18 20:15:45 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

/* Checks if the filename given as argument has the required extension*/

int	check_extension(const char *filename, char *extension)
{
	const char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext || ext == filename)
	{
		printf("Not a valid filename - the file should have an extension\n");
		return (0);
	}
	if (ft_strncmp(ext, extension, 4))
	{
		printf("Not a valid filename - the extension is not correct\n");
		return (0);
	}
	return (1);
}

/* Checks if the arguments that user gave are 2 (executable name, map file)*/

int	check_number_of_arguments(int argc)
{
	if (argc == 2)
		return (1);
	printf("Wrong number of arguments! Valid input -> ./cub3d map_filename\n");
	return (0);
}

/* Checks if filename exists and if we have the right permissions to access it*/

int	check_if_file_exists(int fd, const char *filename)
{
	if (fd == -1)
	{
		printf("File %s: doesn't exist or ", filename);
		printf("you don't have the right permissions to open it\n");
		return (0);
	}
	return (1);
}

/* If filename exists it returns its file descriptor else returns 0*/

int	get_file_descriptor(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (check_if_file_exists(fd, filename))
		return (fd);
	return (0);
}

/* Checks if the input is valid and returns the file descriptor*/

int	is_input_valid(int argc, char *argv[])
{
	int	fd;

	fd = 0;
	if (check_number_of_arguments(argc))
	{
		if (check_extension(argv[1], ".cub"))
			fd = get_file_descriptor(argv[1]);
	}
	return (fd);
}
