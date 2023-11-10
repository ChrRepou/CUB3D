/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:25:51 by crepou            #+#    #+#             */
/*   Updated: 2023/11/10 17:31:30 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "cub3d_errors_bonus.h"
# include "utils_bonus.h"

# define WIDTH 1280
# define HEIGHT 800
# define TRUE 1
# define FALSE 0
# define MOVE_SPEED 0.1
# define TURN_SPEED 0.02

typedef struct cub3d_color
{
	int	red;
	int	blue;
	int	green;
}				t_color;

typedef enum cub3d_orientation
{
	E,
	S,
	W,
	N,
}		t_orientation;

typedef struct cub3d_player_info
{
	double			x_pos;
	double			y_pos;
	mlx_image_t		*mini_player;
	t_orientation	orientation;
	double			angle;
}				t_player;

typedef struct cub3d_info
{
	char			*north_texture;
	char			*south_texture;
	char			*east_texture;
	char			*west_texture;
	t_color			floor_rgb;
	t_color			ceiling_rgb;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	uint32_t		floor_color;
	uint32_t		celing_color;
}				t_info;

typedef struct cub3d_line
{
	char				*ln;
	int					width;
	struct cub3d_line	*next;
}				t_line;

typedef struct s_cub3d
{
	mlx_t						*window;
	mlx_image_t					*img;
	t_player					*player;
	struct s_raycaster			*raycaster;
	char						**map;
	int							width;
	int							height;
	int							index;
	t_info						*info;
	struct s_minimap			*minimap;
}				t_cub3d;

typedef struct s_raycaster	t_caster;
typedef struct s_minimap	t_minimap;

// map will be represented as a 2d array [][]

/************************* parse.c ************************/
int		save_information(t_info *map_info, char *line);
int		get_color(char *line, t_color *color, uint32_t *pixel_color);
int		save_map(t_cub3d *cub3d_info, char *curr_line, int fd);
int		create_map_array(t_line *head, t_cub3d *cub3d_info);
int		save_line(char *line, t_cub3d **cub3d_info, int index);

/********************** file_check.c *********************/
int		files_exist(t_info *map_info);
int		read_file(int fd, t_cub3d *cub3d_info);

/********************** memory.c *********************/
void	free_map_lines(t_line *line);
void	garbage_collector(t_cub3d *cub3d_info);
void	delete_images(t_cub3d *cub3d_info);
void	free_map(t_cub3d *cub3d_info);
void	free_info(t_cub3d *cub3d_info);

/********************** string_manipulation.c *********************/
int		is_orientation(char c, t_cub3d *cub3d_info, int x, int y);
void	print_map(t_cub3d *cub3d_info);

/********************** init.c *********************/
int		init_list(t_line **tail, t_line **head, char *curr_line);
void	init_map(t_cub3d **cub3d_info);

/************** information_retrieval.c ***************/
void	print_list(t_line *head);
int		get_width(t_line *head);

/************** map_check.c ***************/
int		map_is_valid(t_cub3d *cub3d_info);
int		check_row(char *line);
int		check_row_reverse(char *line, int width);
int		check_left_wall(t_cub3d *cub3d_info);
int		check_right_wall(t_cub3d *cub3d_info);

/************** map_check2.c ***************/
int		check_top_wall(t_cub3d *cub3d_info);
int		check_column(t_cub3d *cub3d_info, int x);
int		check_column_reverse(t_cub3d *cub3d_info, int x);
int		check_bottom_wall(t_cub3d *cub3d_info);

/************** player_check.c ***************/
int		has_one_player(t_cub3d *cub3d_info);
int		player_can_move(t_cub3d *cub3d_info);

/************** replace.c ***************/
int		replace_spaces(t_cub3d *cub3d_info);

/************** initiate.c ***************/
int		initiate_mlx(t_cub3d *cub3d_data);
int		initiate_textures(t_cub3d *cub3d);

/************** cub3d.c ***************/
int		initiate_cub3d(t_cub3d *cub3d_data, t_caster *cast_data);
void	init_struct(t_cub3d *cub3d_data);

/************** hooks.c ***************/
void	esc_keyfunc(mlx_key_data_t keydata, void *param);
void	gen_hooks(t_cub3d	*cub3d_data);

/************** movements.c ***************/
void	move_forward(t_player *player, char **map, double x, double y);
void	move_backward(t_player *player, char **map, double x, double y);
void	move_right(t_player *player, char **map, double x, double y);
void	move_left(t_player *player, char **map, double x, double y);

/************** draw/draw.c ***************/
void	my_put_pixel(mlx_image_t *image, int x, int y, uint32_t color);

/************** parse/parse_utils.c.c ***************/
char	*create_expanded_line(t_cub3d *cub3d_info, t_line *list);
void	create_map_line(t_line *map_lines, char *curr_line);

#endif