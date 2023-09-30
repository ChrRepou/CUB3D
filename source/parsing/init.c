/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:06:00 by crepou            #+#    #+#             */
/*   Updated: 2023/09/30 17:15:21 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

int	init_list(t_line **tail, t_line **head, char *curr_line)
{
	if (!curr_line)
		return (printf("Error!\n There is not map to parse\n"), FALSE);
	*tail = (t_line *)malloc(sizeof(t_line));
	if (!(*tail))
		return (printf("Error!\n Map allocation problem\n"), FALSE);
	(*tail)->ln = curr_line;
	(*tail)->next = NULL;
	*head = *tail;
	return (TRUE);
}
