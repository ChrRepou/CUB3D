/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_minimap_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:15:51 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/18 18:16:39 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MINIMAP_BONUS_H
# define CUB3D_MINIMAP_BONUS_H

# define MINI_H 350
# define MINI_W 350
# define WALL_COLOR 0x333333FF
# define PLAYER_COLOR 0xFF0000FF
# define SPACE_COLOR 0xCCCCCCFF
# define DOOR_COLOR 0x999999FF

typedef struct cub3d_player_info	t_player;
typedef struct s_cub3d				t_cub3d;

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

int		init_minimap(t_cub3d *cub3d_data, t_minimap *minimap);
void	draw_player(mlx_image_t *img, double angle);
void	draw_line(mlx_image_t *img, t_2d s_p1, t_2d s_p2);
void	draw_minimap(t_cub3d *data);
void	move_miniplayer(t_player *player);

#endif