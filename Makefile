NAME = fract-ol
CC = cc
FLAGS = -Wall -Wextra -Werror	 -g3 -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
RM = rm -rf


SRCS = srcs/julia.c\
	srcs/main.c\
	srcs/burning_ship.c\
	srcs/utils.c\
	srcs/instructions.c\
	srcs/mandelbrot.c\
	srcs/atoi.c\
	srcs/init.c

PRINTF_SRCS = ft_printf/*.c

PRINTF = ft_printf/libftprintf.a
LIBS = ft_printf/libftprintf.a mlx_linux/libmlx_Linux.a mlx_linux/libmlx.a
OBJ = ${SRCS:.c=.o} ${PRINTF_SRCS:.c=.o}


all: install $(NAME)

$(NAME): $(OBJ)
	@echo "🔨 Building $(NAME)..."
	@make -C ft_printf/ > /dev/null
	@$(CC) $(SRCS) $(PRINTF_SRCS) $(LIBS) $(FLAGS) -o $(NAME)
	@$(RM) srcs/*.o
	@echo "✅ $(NAME) built successfully!"


%.o: %.c
	@$(CC) -Wall -Wextra -Werror -c $< -o $@

mlx_linux:
	@if [ ! -d "mlx_linux" ]; then \
		echo "📥 Cloning mlx_linux..."; \
		git clone https://github.com/42Paris/minilibx-linux.git mlx_linux > /dev/null 2>&1; \
	fi
	@echo "⚙️ Building MiniLibX..."
	@make -C mlx_linux/ > /dev/null
	@echo "✅ MiniLibX built successfully!"


install: mlx_linux ft_printf

clean:
	@echo "🧹 Cleaning..."
	@$(RM) $(OBJ)
	@make -C ft_printf/ clean > /dev/null
	@if [ -d "mlx_linux" ]; then \
		make -C mlx_linux/ clean > /dev/null; \
	fi
	@echo "✅ Cleaned all files!"

fclean: clean
	@echo "🗑️ Removing $(NAME)..."
	@$(RM) $(NAME)
	@make -C ft_printf/ fclean > /dev/null
	@$(RM) mlx_linux
	@echo "✅ Full clean done!"

re: fclean all

.PHONY: all clean fclean re install mlx_linux
