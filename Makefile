NAME = cub3d
NAME_BONUS = cub3d_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast -g3 #-fsanitize=address
INCLUDE = -I ./gnl -I ./libft

SRCS = ./source/main.c	./source/cub3d.c ./source/initiate.c ./source/hooks.c ./source/movement.c \
./source/error_handling/input_check.c ./source/error_handling/file_check.c ./source/error_handling/info_check.c \
./source/error_handling/map_check.c ./source/error_handling/map_check2.c ./source/error_handling/player_check.c \
./source/parsing/parse.c ./source/parsing/init.c ./source/parsing/replace.c ./source/parsing/parse_utils.c\
./source/utils/string_manipulation.c ./source/utils/memory.c ./source/utils/information_retrieval.c ./source/utils/printing.c \
./source/utils/math.c ./source/utils/colors.c \
./source/raycasting/raycaster.c ./source/raycasting/single_ray.c ./source/raycasting/single_ray_2.c \
./source/raycasting/texture.c ./source/raycasting/raycasting_utils.c\
./source/draw/draw.c

SRCS_BONUS = ./source_bonus/main_bonus.c ./source_bonus/cub3d_bonus.c ./source_bonus/initiate_bonus.c ./source_bonus/hooks_bonus.c ./source_bonus/movement_bonus.c \
./source_bonus/error_handling/input_check_bonus.c ./source_bonus/error_handling/file_check_bonus.c ./source_bonus/error_handling/info_check_bonus.c \
./source_bonus/error_handling/map_check_bonus.c ./source_bonus/error_handling/map_check2_bonus.c ./source_bonus/error_handling/player_check_bonus.c \
./source_bonus/parsing/parse_bonus.c ./source_bonus/parsing/init_bonus.c ./source_bonus/parsing/replace_bonus.c ./source_bonus/parsing/parse_utils_bonus.c \
./source_bonus/utils/string_manipulation_bonus.c ./source_bonus/utils/memory_bonus.c ./source_bonus/utils/information_retrieval_bonus.c ./source_bonus/utils/printing_bonus.c \
./source_bonus/utils/math_bonus.c ./source_bonus/utils/colors_bonus.c \
./source_bonus/raycasting/raycaster_bonus.c ./source_bonus/raycasting/single_ray_bonus.c ./source_bonus/raycasting/single_ray_2_bonus.c \
./source_bonus/raycasting/texture_bonus.c ./source_bonus/raycasting/raycasting_utils_bonus.c\
./source_bonus/draw/draw_bonus.c \
./source_bonus/minimap/draw_minimap_bonus.c ./source_bonus/minimap/init_minimap_bonus.c ./source_bonus/minimap/draw_line_bonus.c ./source_bonus/minimap/draw_player_bonus.c

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft/
LIBMLX = ./MLX42

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: gnl libft libmlx $(NAME)
bonus: gnl libft libmlx $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -march=nocona -flto $(INCLUDE) $(OBJS) -L$(LIBMLX) -L./gnl/ -lgnl -L./libft -lft -lmlx42 -L "$(shell brew --prefix glfw)/lib/" -lglfw  -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -march=nocona -flto $(INCLUDE) $(OBJS_BONUS) -L$(LIBMLX) -L./gnl/ -lgnl -L./libft -lft -lmlx42 -L "$(shell brew --prefix glfw)/lib/" -lglfw  -o $(NAME_BONUS)

libmlx:
	${MAKE} -C $(LIBMLX)

libft:
	${MAKE} -C $(LIBFT_DIR)

gnl:
	${MAKE} -C ./gnl/

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@${MAKE} clean -C $(LIBMLX)
	@${MAKE} clean -C ./gnl/

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@${MAKE} -C $(LIBMLX) fclean
	@${MAKE} -C ./gnl/ fclean

re: fclean all

.PHONY: all re fclean clean gnl libft printf