/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:51:54 by crepou            #+#    #+#             */
/*   Updated: 2023/09/28 16:09:01 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

# include "./cub3d.h"

/************************* parse.c ************************/
int	save_map(int **map, char *curr_line, int fd);

#endif