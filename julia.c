
#include "fractol.h"


// void	my_mlx_pixel_put(s_fractal *fractal, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = fractal->addr + (y * fractal->line_length + x * (fractal->bits_per_pixel / 8));
	
// 	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
// 	    *(unsigned int *)(dst) = color;

// }

// void clear(s_fractal *fractal)
// {
//     int new_x;
//     int new_y = 0;
// 	int color;
    
//     while (new_y <= WINDOW_HEIGHT)
//     {
//         new_x = 0;
//         while (new_x <= WINDOW_WIDTH)
//         {on_destroy_event
//     }
//     mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
// }


int	calculate_julia_color(double z_x, double z_y, s_fractal *fractal)
{
	int max_iterations = 100;
	int iteration = 0;
	double temp;

	while ((z_x * z_x + z_y * z_y <= 4) && (iteration < max_iterations))
	{
		temp = z_x * z_x - z_y * z_y + fractal->c_re; 
		z_y = 2.0 * z_x * z_y + fractal->c_i;
		z_x = temp;
		iteration++;
	}
	if (iteration == max_iterations)
		return 0x000000;
	return (iteration * fractal->adress);
}

void	draw_julia(s_fractal *fractal)
{
    int new_y = 0;
    int new_x = 0;
    double z_x = 0;
    double z_y = 0;
    double scale = WINDOW_WIDTH / (fractal->zoom * 4); 
	int color;

	// clear(fractal);
	mlx_clear_window(fractal->mlx, fractal->win);
    while (new_y <= WINDOW_HEIGHT)
    {
        new_x = 0;
        while (new_x <= WINDOW_WIDTH)
        {
            z_x = fractal->start_x +  (new_x - WINDOW_WIDTH / 2) / scale;
            z_y = fractal->start_y + (new_y - WINDOW_HEIGHT / 2) / scale;
            color = calculate_julia_color(z_x, z_y, fractal);
            ((int *)fractal->addr)[new_y * WINDOW_WIDTH + new_x] = color;
            new_x++;
        }
        new_y++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

