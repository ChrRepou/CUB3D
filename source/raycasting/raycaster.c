/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:37:23 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/06 21:45:49 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"
#include "../../header_files/cub3d_raycasting.h"

/* Filed of view is 60 degrees or M_PI/3, 
30 degrees or radians from center is M_PI/6 */
void	initiate_casting(t_caster *cast_data)
{
	cast_data->proj_distance = (WIDTH / 2) / tan((M_PI / 6));
	cast_data->ray_angle_step = M_PI / 3 / (double)WIDTH;
	// cast_data->center_x_px = WIDTH / 2;
	// cast_data->center_y_px = HEIGHT / 2;
	printf("RAYCASTER \n");
	printf("distance of screen: %f  angle between rays: %f\n", \
		cast_data->proj_distance, cast_data->ray_angle_step);
}

// static void	reset_ray_data(t_ray *ray)
// {
// 	ray->true_angle = 0;
// 	ray->hit_x = 0;
// 	ray->hit_y = 0;
// 	ray->distance = 0;
// 	ray->hit_wall = 0;
// }

/*Clears image before drawing another one,
keeps up which pixel column is being cast (and drawn) and 
what is the angle of the ray*/

void draw_raycast_image(t_cub3d *cub3d_data)
{
	int		ray_i;
	double	ray_angle;

	// unsigned int 	pixel_i;
	// int		y = 300;
	// uint32_t color;
	// t_color rgb;

	ft_memset(cub3d_data->img->pixels, 0, cub3d_data->img->width * \
	cub3d_data->img->height * sizeof(int32_t));
	ray_i = 0;
	ray_angle = -(M_PI / 6);
	while (ray_i < WIDTH)
	{
		draw_column(cub3d_data, ray_angle, ray_i);
		ray_i++;
		ray_angle = ray_angle + cub3d_data->raycaster->ray_angle_step;
	}
	// pixel_i = 5;
	// while (pixel_i < cub3d_data->info->east->height * cub3d_data->info->east->width)
	// {
	// 	rgb.red = cub3d_data->info->east->pixels[pixel_i * 4];
	// 	rgb.green = cub3d_data->info->east->pixels[pixel_i * 4 + 1];
	// 	rgb.blue = cub3d_data->info->east->pixels[pixel_i * 4 + 2];
	// 	// ft_memcpy(&cub3d_data->img->pixels[(WIDTH * y + 300) * 4], (&cub3d_data->info->north->pixels[pixel_i * 4]), 4);
	// 	color = rgb_to_color(rgb);
	// 	my_put_pixel(cub3d_data->img, 300, y, color);
	// 	y++;
	// 	pixel_i += cub3d_data->info->east->width;
	// }
	
	// mlx_draw_texture(cub3d_data->img, cub3d_data->info->north, 300, 300);
	// mlx_draw_texture(cub3d_data->img, cub3d_data->info->east, 300, 600);
	// mlx_draw_texture(cub3d_data->img, cub3d_data->info->east, 600, 300);
	// mlx_draw_texture(cub3d_data->img, cub3d_data->info->west, 600, 600);
}


// void draw_raycast_image(t_cub3d *cub3d_data)
// {
// 	int		ray_i;
// 	double	ray_angle;

// 	unsigned int 	pixel_i;
// 	int		y = 300;
// 	uint32_t color;
// 	t_color rgb;
// 	double strecher = 0;
	

// 	ft_memset(cub3d_data->img->pixels, 0, cub3d_data->img->width * \
// 	cub3d_data->img->height * sizeof(int32_t));
// 	ray_i = 0;
// 	ray_angle = -(M_PI / 6);
// 	while (ray_i < WIDTH)
// 	{
// 		draw_column(cub3d_data, ray_angle, ray_i);
// 		ray_i++;
// 		ray_angle = ray_angle + cub3d_data->raycaster->ray_angle_step;
// 	}
// 	pixel_i = 0;
// 	while ((int)strecher * cub3d_data->info->east->width + pixel_i < cub3d_data->info->east->height * cub3d_data->info->east->width)
// 	{
// 		rgb.red = cub3d_data->info->east->pixels[((int)strecher * cub3d_data->info->east->width + pixel_i) * 4];
// 		rgb.green = cub3d_data->info->east->pixels[((int)strecher * cub3d_data->info->east->width + pixel_i) * 4 + 1];
// 		rgb.blue = cub3d_data->info->east->pixels[((int)strecher * cub3d_data->info->east->width + pixel_i) * 4 + 2];
// 		// ft_memcpy(&cub3d_data->img->pixels[(WIDTH * y + 300) * 4], (&cub3d_data->info->north->pixels[pixel_i * 4]), 4);
// 		color = rgb_to_color(rgb);
// 		my_put_pixel(cub3d_data->img, 300, y, color);
// 		y++;
// 		strecher += 1;
// 		// pixel_i += ((int)strecher * cub3d_data->info->east->width);
// 		// pixel_i += cub3d_data->info->east->width;
		
// 	}
	
// 	// mlx_draw_texture(cub3d_data->img, cub3d_data->info->north, 300, 300);
// 	// mlx_draw_texture(cub3d_data->img, cub3d_data->info->east, 300, 600);
// 	mlx_draw_texture(cub3d_data->img, cub3d_data->info->east, 600, 300);
// 	// mlx_draw_texture(cub3d_data->img, cub3d_data->info->west, 600, 600);
// }


