NAME = fractal
CC = cc
FLAGS = -Wall -Wextra  -g3 -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
RM = rm -rf

SRCS =	*.c
PRINTF_SRCS =	ft_printf/*.c

PRINTF = ft_printf/libftprintf.a
LIBS = ft_printf/libftprintf.a mlx_linux/libmlx_Linux.a mlx_linux/libmlx.a
OBJ = ${SRCS:.c=.o} ${PRINTF_SRCS:.c=.o}

$(NAME): $(OBJ)
	make -C ft_printf/
	$(CC) $(SRCS) $(PRINTF_SRCS) $(LIBS) $(FLAGS) -o $(NAME)


%.o: %.c
	$(CC) -Wall -Wextra -Werror -g3 -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

clean: 
	$(RM) $(OBJ)


fclean: clean
	$(RM) $(NAME)
	make -C ft_printf/ fclean

re: fclean all

.PHONY: all clean fclean re