/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:37:23 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/22 21:21:14 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
#include "../../header_files/cub3d_raycasting.h"

void	initiate_casting(t_caster *rays)
{
	double	rad_from_centre;

	rad_from_centre = (FIELD_OF_VIEW / 2) * (M_PI / 180);
	rays->proj_distance = (WIDTH / 2) / tan(rad_from_centre);
	rays->ray_angle_step = (double)FIELD_OF_VIEW / (double)WIDTH;
	rays->center_x_px = WIDTH / 2;
	rays->center_y_px = HEIGHT / 2;
	printf("RAYCASTER \n");
	printf("distance of screen: %f  angle between rays: %f\n", \
		rays->proj_distance, rays->ray_angle_step);
}

