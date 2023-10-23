/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycasting.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:24:57 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/23 19:56:52 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYCASTING_H
# define CUB3D_RAYCASTING_H

# define CUBE_SIDE 126
# define PLAYER_EYELINE 64
# define ANGLE_TOLERANCE 0.002

# include "cub3d.h"

typedef struct s_raycaster
{
	double	proj_distance;
	double	ray_angle_step;
	int		center_y_px;
	int		center_x_px;
}	t_caster;

typedef struct s_ray
{
	double	hit_x;
	double	hit_y;
	int		modifier;
	int		direction;
}	t_ray;


void	initiate_casting(t_caster *rays);
double	get_ray_length(t_cub3d *cub3d_data, double ray_angle);

#endif