

#include "fractol.h"


void instructions_display()
{
	ft_printf("%s", oneline);
	ft_printf("%s", twoline);
	ft_printf("%s", threeline);
	ft_printf("%s", fourline);
	ft_printf("%s", fiveline);
	ft_printf("%s", sixline);
	ft_printf("%s", sevenline);
	ft_printf("%s", eightline);
	ft_printf("%s", nineline);
	ft_printf("%s", tenline);
	ft_printf("%s", elevenline);
}

int	check_name_selection(char *argv, char *chaine)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (chaine[len])
		len++;
	while (i < len)
	{
		if (argv[i] != chaine[i])
			return (0);
		i++;
	}
	return (1);
	
}

void	menu(int argc, char **argv, s_fractal *fractal)
{
	if (argc == 1)
	{
		instructions_display();
		exit(1);
	}
	if (check_name_selection(argv[1], "Julia"))
		fractal->number = 0;
	if (check_name_selection(argv[1], "Mandelbrot"))
		fractal->number = 1;
	if (argc >= 3)
		fractal->c_re = ft_atoi(argv[2]);
	if (argc == 4)
		fractal->c_i = ft_atoi(argv[3]);
}



void draw(s_fractal *fractal)
{
	if (fractal->number == 0)
	{
		draw_julia(fractal);
	}
	if (fractal->number == 1)
	{
		draw_mandelbrot(fractal);
	}
}

int main(int argc, char **argv)
{
	s_fractal	*fractal;

	fractal = malloc(sizeof(s_fractal));
	if (!fractal)
		exit(1);
	fractal->c_re = -0.7;
	fractal->c_i = 0.3;
	fractal->zoom = 1.0;
	fractal->start_x = 0;
	fractal->start_y = 0;
	menu(argc, argv, fractal);

	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		return (1);
	fractal->win = mlx_new_window(fractal->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fract-ol");
	fractal->img = mlx_new_image(fractal->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);

	malloc_color(fractal);
	draw(fractal);
	
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	key_pressure(fractal);
}