/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:50:06 by crepou            #+#    #+#             */
/*   Updated: 2023/11/09 21:08:29 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

/*
The function returns all the 3 colors of rgb into one integer color
*/
uint32_t	rgb_to_color(t_color c)
{
	int	color;

	color = (c.red << 24) | (c.green << 16) | (c.blue << 8) | 0xFF;
	return (color);
}
