/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:58:23 by crepou            #+#    #+#             */
/*   Updated: 2023/09/30 14:44:51 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
/*
returns the string contained in the line starting 
from index: start_index until index:end_index

if the end_index is 0 then it goes until the end of the string

implements malloc so it has to be free, it doesn't free the line
*/
char	*get_info(char *line, int start_index, int end_index)
{
	char	*new_line;
	int		i;

	if (end_index == -1)
	{
		end_index = start_index;
		while (line[end_index] != '\n')
			end_index++;
	}
	new_line = (char *)malloc(end_index - start_index + 1);
	i = 0;
	while (start_index < end_index)
	{
		new_line[i] = line[start_index];
		i++;
		start_index++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*char_to_string(char c)
{
	char	*str;

	str = (char *)malloc(2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
