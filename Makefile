NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./gnl -I ./libft
SRCS = ./source/cub3d.c ./source/main.c ./source/error_handling/input_check.c
LIBFT = ./libft/libft.a
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./libft/

LIBMLX = ./MLX42

all: gnl libft libmlx $(NAME)

$(NAME): $(OBJS)
	$(CC) -Ofast -march=nocona -flto $(INCLUDE) $(OBJS) -L$(LIBMLX) -L./gnl/ -lgnl -L./libft -lft -lmlx42 -L "$(shell brew --prefix glfw)/lib/" -lglfw  -o $(NAME)

bonus: gnl libft libmlx $(NAME)

libmlx:
	${MAKE} -C $(LIBMLX)

libft:
	${MAKE} -C $(LIBFT_DIR)

gnl:
	${MAKE} -C ./gnl/

clean:
	@rm -f $(OBJS)
	@${MAKE} clean -C $(LIBMLX)
	@${MAKE} clean -C ./gnl/

fclean: clean
	@rm -f $(NAME)
	@${MAKE} -C $(LIBMLX) fclean
	@${MAKE} -C ./gnl/ fclean

re: fclean all

.PHONY: all re fclean clean gnl libft printf