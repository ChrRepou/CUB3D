/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:46 by crepou            #+#    #+#             */
/*   Updated: 2023/09/23 14:15:32 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	main(int argc, char *argv[])
{
	int	fd;

	fd = is_input_valid(argc, argv);
	if (!fd)
		return (-1);
	read_file(fd);
	return (0);
}
