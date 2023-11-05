/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_minimap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:15:51 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/05 21:19:40 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MINIMAP_H
# define CUB3D_MINIMAP_H

# define MINI_H 200
# define MINI_W 300
# define WALL_COLOR 0x333333FF
# define PLAYER_COLOR 0xFF0000FF
# define SPACE_COLOR 0xCCCCCCFF

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct cub3d_player_info	t_player_info;

typedef struct s_minimap
{
	mlx_image_t	*img_mini;
	mlx_image_t	*img_player;
	int			tile_h;
}	t_minimap;

typedef struct s_mini_draw
{
	int			x_px;
	int			y_px;
	int			x_tile;
	int			y_tile;
	uint32_t	color;
}	t_mini_draw;

typedef struct s_2d {
	int			x;
	int			y;
	uint32_t	pt_rgba;
}	t_2d;

typedef struct s_px {
	int		step;
	int		dx;
	int		dy;
}	t_px;

void	draw_player(mlx_image_t *img, double angle);
void	draw_line(mlx_image_t *img, t_2d s_p1, t_2d s_p2);


#endif