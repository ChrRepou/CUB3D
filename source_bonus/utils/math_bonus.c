/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:06:39 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/08 18:10:22 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files_bonus/cub3d_bonus.h"

//returns the radian angle of start position
double	get_angle(t_orientation cub3d_orientation)
{
	if (cub3d_orientation == E)
		return (0);
	if (cub3d_orientation == S)
		return (M_PI_2);
	if (cub3d_orientation == W)
		return (M_PI);
	if (cub3d_orientation == N)
		return (M_PI + M_PI_2);
	return (0);
}
