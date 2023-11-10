/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:10:18 by crepou            #+#    #+#             */
/*   Updated: 2023/11/10 15:54:02 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

char	*create_expanded_line(t_cub3d *cub3d_info, t_line *list)
{
	char	*expand_line;
	char	*new_ln;

	expand_line = (char *)malloc(cub3d_info->width - list->width + 1);
	ft_memset(expand_line, 32, cub3d_info->width - list->width);
	new_ln = ft_strjoin(list->ln, expand_line);
	free(expand_line);
	free(list->ln);
	return (new_ln);
}

void	create_map_line(t_line *map_lines, char *curr_line)
{
	map_lines->ln = curr_line;
	map_lines->width = ft_strlen(curr_line);
	map_lines->next = NULL;
}
