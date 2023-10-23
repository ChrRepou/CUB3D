/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:37:23 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/23 19:28:35 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
#include "../../header_files/cub3d_raycasting.h"

// Filed of view id 60 degrees or M_PI/3, 30 degrees or radians from center is M_PI/6

void	initiate_casting(t_caster *rays)
{
	double	rad_from_centre;

	rad_from_centre = (M_PI / 6);
	rays->proj_distance = (WIDTH / 2) / tan(rad_from_centre);
	rays->ray_angle_step = M_PI / 3 / (double)WIDTH;
	rays->center_x_px = WIDTH / 2;
	rays->center_y_px = HEIGHT / 2;
	printf("RAYCASTER \n");
	printf("distance of screen: %f  angle between rays: %f\n", \
		rays->proj_distance, rays->ray_angle_step);
}
