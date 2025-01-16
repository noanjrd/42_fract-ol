
#include "fractol.h"

int	on_destroy_event(s_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	free(fractal);
	exit(1);
}

int print_key(int key, s_fractal *fractal)
{

    if (key == 65363)
    {
        fractal->start_x += 0.1 * fractal->zoom;
        draw(fractal);
    }
    if (key == 65361)
    {
        fractal->start_x -= 0.1 * fractal->zoom;
        draw(fractal);
    }
    if (key == 65364)
    {
        fractal->start_y += 0.1 * fractal->zoom;
        draw(fractal);
    }
    if (key == 65362)
    {
        fractal->start_y -= 0.1 * fractal->zoom;
        draw(fractal);
    }
    if (key == 65307)
		on_destroy_event(fractal);
    if (key == 'q')
    {
		fractal->c_i += 0.01;
        draw(fractal);
    }
    if (key == 'w')
    {
		fractal->c_i -= 0.01;
        draw(fractal);
    }
    if (key == 'a')
    {
		fractal->c_re += 0.01;
        draw(fractal);
    }
    if (key == 's')
    {
		fractal->c_re -= 0.01;
        draw(fractal);
    }
    return (0);
}



int mouse_hook(int button, int x, int y, void *param)
{
    s_fractal *fractal = (s_fractal *)param;

    x = 0;
    y = 0;
    if (button == 5 )
    {
        fractal->zoom *= 1.1;
        draw(fractal);
    }
    else if (button == 4 )
    {
        fractal->zoom *= 0.9;
        draw(fractal);
    }
    return (0);
}

void	malloc_color(s_fractal *fractal)
{
	int *temp;

	temp = malloc(4 * sizeof(char *));
	fractal->adress = temp[0];
	free(temp);
}

void key_pressure(s_fractal *fractal)
{
	mlx_hook(fractal->win, 6, KeyPressMask, mouse_hook, fractal);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
	mlx_key_hook(fractal->win, print_key, fractal);
    mlx_hook(fractal->win, 17, 0, on_destroy_event, fractal);
	mlx_loop(fractal->mlx);
}