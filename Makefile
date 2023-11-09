NAME = cub3d
NAME_BONUS = cub3d_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast -fsanitize=address
INCLUDE = -I ./gnl -I ./libft

SRCS = ./source/main.c	./source/cub3d.c ./source/initiate.c ./source/hooks.c ./source/movement.c \
./source/error_handling/input_check.c ./source/error_handling/file_check.c ./source/error_handling/info_check.c \
./source/error_handling/map_check.c ./source/error_handling/map_check2.c ./source/error_handling/player_check.c \
./source/parsing/parse.c ./source/parsing/init.c ./source/parsing/replace.c \
./source/utils/string_manipulation.c ./source/utils/memory.c ./source/utils/information_retrieval.c ./source/utils/printing.c \
./source/utils/math.c ./source/utils/colors.c \
./source/raycasting/raycaster.c ./source/raycasting/single_ray.c ./source/raycasting/single_ray_2.c \
./source/raycasting/texture.c ./source/raycasting/raycasting_utils.c\
./source/draw/draw.c

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