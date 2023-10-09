/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_minimap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:15:51 by tmarts            #+#    #+#             */
/*   Updated: 2023/10/09 13:56:19 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MINIMAP_H
# define CUB3D_MINIMAP_H

# include "cub3d.h"

# define MINI_H 1000
# define MINI_W 1000
# define WALL_COLOR 0x1CFF8AFF
# define PLAYER_COLOR 0xE00016FF
# define SPACE_COLOR 0x15164AFF

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

int		init_minimap(t_cub3d *cub3d_data, t_minimap *minimap);
int		draw_minimap(t_cub3d *data, t_minimap *minimap);

// void	rotate_player(t_cub3d *data);

#endif