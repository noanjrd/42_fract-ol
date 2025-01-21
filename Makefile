NAME = fract-ol
CC = cc
FLAGS = -Wall -Wextra -g3 -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
RM = rm -rf

SRCS = julia.c\
	main.c\
	burning_ship.c\
	utils.c\
	utils2.c\
	mandelbrot.c\
	atoi.c

PRINTF_SRCS = ft_printf/*.c

PRINTF = ft_printf/libftprintf.a
LIBS = ft_printf/libftprintf.a mlx_linux/libmlx_Linux.a mlx_linux/libmlx.a
OBJ = ${SRCS:.c=.o} ${PRINTF_SRCS:.c=.o}


all: install $(NAME)

$(NAME): $(OBJ)
	make -C ft_printf/
	$(CC) $(SRCS) $(PRINTF_SRCS) $(LIBS) $(FLAGS) -o $(NAME)
	$(RM) *.o

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g3 -I/usr/include -Imlx_linux -O3 -c $< -o $@

mlx_linux:
	@if [ ! -d "mlx_linux" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git mlx_linux; \
	fi
	make -C mlx_linux/

install: mlx_linux ft_printf

clean:
	$(RM) $(OBJ)
	make -C ft_printf/ clean
	@if [ -d "mlx_linux" ]; then \
		make -C mlx_linux/ clean; \
	fi

fclean: clean
	$(RM) $(NAME)
	make -C ft_printf/ fclean
	$(RM) mlx_linux

re: fclean all

.PHONY: all clean fclean re install mlx_linux
