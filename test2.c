#include <stdlib.h>
#include "fractol.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
#define	MLX_ERROR 1


typedef struct	color
{
	int color_b;
	struct color	*next;
}				color;

typedef struct	s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
    double  zoom;
    double     start_x;
    double     start_y;
    double c_re;
    double c_i; 
	color   *colors;
}				s_fractal;

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
//         {
// 			color = 0x000000;
//             ((int *)fractal->addr)[new_y * WINDOW_WIDTH + new_x] = color;
//             new_x++;
//         }
//         new_y++;
//     }
//     mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
// }

int calculate_julia_color(double z_x, double z_y, s_fractal *fractal)
{
    int max_iterations = 200;
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

    return (iteration * 0x123456);
}

void draw(s_fractal *fractal)
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


int mouse_hook(int button, int x, int y, void *param)
{
	s_fractal *fractal = (s_fractal *)param;

	x = 0;
	y = 0;
    if (button == 5 && fractal->zoom > 0.01)
    {
		fractal->zoom *= 1.1;
		draw(fractal);
    }
	else if (button == 4 && fractal->zoom < 500)
	{
		fractal->zoom *= 0.9;
		draw(fractal);
	}
    return (0);
}

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
		printf("%f", fractal->zoom);
        fractal->start_x += 0.1 * fractal->zoom;
        draw(fractal);
    }
    if (key == 65361)
    {
		printf("%f", fractal->zoom);
        fractal->start_x -= 0.1 * fractal->zoom;
        draw(fractal);
    }
    if (key == 65364)
    {
		printf("%f", fractal->zoom);
        fractal->start_y += 0.1 * fractal->zoom;
        draw(fractal);
    }
    if (key == 65362)
    {
		printf("%f", fractal->zoom);
        fractal->start_y -= 0.1 * fractal->zoom;
        draw(fractal);
    }
    printf("Key pressed: %d\n", key);
    return (0);
}


int main(void)
{
	s_fractal	*fractal;

	fractal = malloc(sizeof(s_fractal));
	if (!fractal)
	{
		perror("Error: malloc failed");
		exit(1);
	}

	fractal->c_re = -0.7;
	fractal->c_i = 0.3;
	fractal->zoom = 1.0;
	fractal->start_x = 0;
	fractal->start_y = 0;

	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		return (MLX_ERROR);
	fractal->win = mlx_new_window(fractal->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fract-ol");
	fractal->img = mlx_new_image(fractal->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);

	draw(fractal);
	
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
	mlx_key_hook(fractal->win, print_key, fractal);
    mlx_hook(fractal->win, 17, 0, on_destroy_event, fractal);
	mlx_loop(fractal->mlx);
}