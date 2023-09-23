/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:25:51 by crepou            #+#    #+#             */
/*   Updated: 2023/09/23 11:25:59 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "cub3d_errors.h"

# define WIDTH 1024
# define HEIGHT 1024

char	*so_long(int fd);

typedef struct cub3d_color
{
	int	red;
	int	blue;
	int	green;
}				t_color;

typedef enum cub3d_orientation
{
	N = 0,
	S = 1,
	E = 2,
	W = 3
}		t_orientation;

typedef struct cub3d_player_info
{
	int				x_position;
	int				y_position;
	t_orientation	orientation;
}				t_player_info;


typedef struct cub3d_info
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	t_color	floor_color;
	t_color	ceiling_color;
}				t_info;

// map will be represented as a 2d array [][]

#endif