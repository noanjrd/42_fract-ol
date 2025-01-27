NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS =	ft_printf.c\
	c.c\
	d_i.c\
	s.c\
	u.c\
	x.c\
	X.c\
	ft_itoa.c\
	ft_itoa_u.c\
	p.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $@ 

all: $(NAME)

clean: 
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re