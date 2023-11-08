/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_errors_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:04:01 by crepou            #+#    #+#             */
/*   Updated: 2023/11/08 18:22:21 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERRORS_BONUS_H
# define CUB3D_ERRORS_BONUS_H

# include "cub3d_bonus.h"

typedef struct s_cub3d	t_cub3d;

/************** input_check.c **************/
int		check_extension(const char *filename);
int		check_number_of_arguments(int argc);
int		check_if_file_exists(int fd, const char *filename);
int		get_file_descriptor(const char *filename);
int		is_input_valid(int argc, char *argv[]);

/************** file_check.c ***************/
int		is_empty_file(char **line, int fd);
int		is_info(char *line);

/************** info_check.c ***************/
int		is_number(char *input);
#endif