/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycasting.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:24:57 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/28 21:52:40 by tmarts           ###   ########.fr       */
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
	double			proj_distance;
	double			ray_angle_step;

	// int				center_y_px;
	// int				center_x_px;
}	t_caster;

// typedef struct s_ray
// {
// 	// double			ray_angle;
// 	// double			true_angle;
// 	// int				ray_index;
// 	double			hit_x;
// 	double			hit_y;
// 	// double			r_angle;
// 	// double			true_angle;
// 	int				modifier;
// 	int				direction;
// 	// double			distance;
	
// 	t_orientation	wall_hit;
// 	// double			distance;
// } t_ray;

typedef struct s_ray
{
	// double			ray_angle;
	// double			true_angle;
	// int				ray_index;
	double			hit_x;
	double			hit_y;
	double			r_angle; //
	double			true_angle; //
	int				modifier;
	int				direction;
	// double			distance;
	
	t_orientation	wall_hit; //
	// double			distance;
} t_ray;

typedef struct s_ray_utils
{
	int			modifier;
	int			direction;
	t_player	*O_pt;
}  t_ray_utils;

// typedef struct	s_intersect
// {
// 	double	next_x;
// 	double	next_y;
// 	int		modifier;
// 	int		direction;
// 	double 	dist;
	
// } t_intersect;

typedef struct s_pt
{
	double 	x;
	double 	y;
	double	distance;
} t_pt;

void	initiate_casting(t_caster *cast_data);
// double	get_ray_length(t_cub3d *cub3d_data, double ray_angle);
// void	draw_column(t_cub3d *cub3d_data, t_caster *cast_data, double ray_angle);
void	draw_column(t_cub3d *cub3d_data, double ray_angle, int ray_i);
// void	draw_column(t_cub3d *cub3d_data, t_caster *cast_data, t_ray *ray_data);
void	draw_raycast_image(t_cub3d *cub3d_data);

bool	wall_hit(char **map, int x, int y);
double	remove_distortion(double distance, double angle_offcenter);
double	get_true_angle(double player_angle, double ray_angle);
#endif