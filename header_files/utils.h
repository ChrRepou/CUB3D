/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:00:30 by crepou            #+#    #+#             */
/*   Updated: 2023/09/27 19:16:36 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/************** string_manipulation.c **************/
char	*get_info(char *line, int start_index, int end_index);

/******************** memory.c *********************/
void	free_after_split(char **array);

#endif