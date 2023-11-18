/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycasting_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:24:57 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/18 14:27:22 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYCASTING_BONUS_H
# define CUB3D_RAYCASTING_BONUS_H

# define CUBE_SIDE 126
# define PLAYER_EYELINE 64
# define ANGLE_TOLERANCE 0.002

# include "cub3d_bonus.h"

typedef struct s_raycaster
{
	double			proj_distance;
	double			ray_angle_step;
}	t_caster;

typedef struct s_ray
{
	double			true_angle;
	double			hit_x;
	double			hit_y;
	t_orientation	wall;
	double			distance;
	int				wall_h;
	mlx_texture_t	*texture;
}	t_ray;

typedef struct s_pt
{
	double	x;
	double	y;
}	t_pt;

typedef struct s_ray_utils
{
	int			modifier;
	double		increment_x;
	double		increment_y;
	t_player	*pt_0;
}	t_ray_utils;

/************** raycaster.c **************/
void			initiate_casting(t_caster *cast_data);
void			draw_raycast_image(t_cub3d *cub3d_data);

/************** single_ray.c **************/
void			get_ray_data(t_cub3d *cub3d, t_ray *ray, double ray_angle);

/************** single_ray_2.c **************/
void			draw_column(t_cub3d *cub3d_data, double ray_angle, int ray_i);

/************** texture.c **************/
int				draw_texture_column(t_cub3d *cub3d, t_ray *ray, \
											int ray_i, int y_start);

/************** raycasting_utils.c **************/
bool			valid_coords(const t_pt *point, int map_width, int map_height);
bool			is_wall_hit(char **map, int x, int y);
t_orientation	get_wall(double angle, char hit_axis);
double			remove_distortion(double distance, double angle_offcenter);
// double			get_true_angle(double player_angle, double ray_angle);

#endif