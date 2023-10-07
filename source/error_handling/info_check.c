/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:22:19 by crepou            #+#    #+#             */
/*   Updated: 2023/09/28 11:07:53 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

/* 
The function returns true if the input is a number 
(doesn't contain special characters or letters)
*/
int	is_number(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
