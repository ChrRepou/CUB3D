/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information_retrieval.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:05:34 by crepou            #+#    #+#             */
/*   Updated: 2023/09/30 16:59:45 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

/* it gets the width of a line */
int	get_width(char *line)
{
	int	width;

	width = 0;
	while (line[width] && line[width] != '\n')
		width++;
	return (width);
}

/* It prints a list */
void	print_list(t_line *head)
{
	int	i;

	i = 0;
	while (head)
	{
		printf("Line %d: %s\n", i, head->ln);
		i++;
		head = head->next;
	}
}
