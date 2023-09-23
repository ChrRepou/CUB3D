/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:04:01 by crepou            #+#    #+#             */
/*   Updated: 2023/09/16 12:49:57 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERRORS_H
# define CUB3D_ERRORS_H

/************** input_check.c **************/
int	check_extension(const char *filename);
int	check_number_of_arguments(int argc);
int	check_if_file_exists(int fd, const char *filename);
int	get_file_descriptor(const char *filename);
int	is_input_valid(int argc, char *argv[]);

#endif