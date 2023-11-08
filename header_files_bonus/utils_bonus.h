/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:00:30 by crepou            #+#    #+#             */
/*   Updated: 2023/11/08 18:22:54 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

typedef enum cub3d_orientation	t_orientation;
typedef struct cub3d_color		t_color;

/************** string_manipulation.c **************/
char		*get_info(char *line, int start_index, int end_index);
char		*char_to_string(char c);
void		free_after_split(char **array);

/******************** information_retrieval.c *********************/
int			is_player(char info);

/******************** printing.c *********************/
void		print(char *string);
void		print_s(char *string, char *argument);
void		print_mixed(char *string, char *argument, int argument2);

/******************** colors.c *********************/
uint32_t	rgb_to_color(t_color c);

/******************** math.c *********************/
double		get_angle(t_orientation cub3d_orientation);

#endif