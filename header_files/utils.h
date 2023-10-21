/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:00:30 by crepou            #+#    #+#             */
/*   Updated: 2023/10/21 20:49:23 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/************** string_manipulation.c **************/
char	*get_info(char *line, int start_index, int end_index);
char	*char_to_string(char c);

/******************** memory.c *********************/
void	free_after_split(char **array);

/******************** information_retrieval.c *********************/
int		is_player(char info);

/******************** printing.c *********************/
void	print(char *string);
void	print_s(char *string, char *argument);
void	print_mixed(char *string, char *argument, int argument2);

#endif