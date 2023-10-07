CC = cc
CFLAGS  = -Wall -Wextra -Werror
NAME = libgnl.a
GNL = get_next_line.c get_next_line_utils.c \

obj = $(cd:.c=.o)
GNL_OBJ = ${GNL:.c=.o}

all: $(NAME)

$(NAME): $(obj) $(GNL_OBJ)
	ar rcs $(NAME) $(obj) $(GNL_OBJ)

fclean: clean
	@$(RM) $(NAME)

clean:
	@$(RM) $(obj) $(GNL_OBJ)

re: fclean all clean