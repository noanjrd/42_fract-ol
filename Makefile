NAME = fractal
CC = cc
FLAGS = -Wall -Wextra -Werror -g3 
RM = rm -rf


SRCS =	test2.c\

OBJ := ${SRCS:.c=.o}

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


%.o: %.c
	$(CC) -Wall -Wextra -Werror -g3 -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

clean: 
	$(RM) $(OBJ) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re