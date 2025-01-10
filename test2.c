 // prochaine etape faire le zoom

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
    int     start_x;
    int     start_y;
	color   *colors;
}				s_fractal;



void	my_mlx_pixel_put(s_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x * (fractal->bits_per_pixel / 8));
	*(unsigned int*)(dst) = color;
}

void clear(s_fractal *fractal)
{
    int new_x;
    int new_y = 0;
    
    while (new_y <= WINDOW_HEIGHT)
    {
        new_x = 0;
        while (new_x <= WINDOW_WIDTH)
        {
            my_mlx_pixel_put(fractal, new_x, new_y, 0x000000);
            new_x++;
        }
        new_y++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

void draw(s_fractal *fractal, color *copy)
{
    int new_x;
    int new_y = 0;
	int stripe_width = 10;

	clear(fractal);
    while (new_y <= WINDOW_HEIGHT && new_y <= 200 * fractal->zoom)
    {
        new_x = 1 * fractal->zoom;
        while (new_x <= WINDOW_WIDTH && new_x <= 100 * fractal->zoom)
        {
            int stripe_index = new_x / stripe_width; 

            if (stripe_index > 0) 
            {
                copy = copy->next; 
                if (copy == NULL) 
                {
                    copy = fractal->colors;
                }
            }
            my_mlx_pixel_put(fractal, new_x, new_y, copy->color_b);
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
    if (button == 4 && fractal->zoom < 500.0)
    {
        fractal->zoom *= 1.1;
        mlx_clear_window(fractal->mlx, fractal->win);
        draw(fractal, fractal->colors);
    }
    else if (button == 5 && fractal->zoom > -500)
    {
        fractal->zoom *= 0.9;
        mlx_clear_window(fractal->mlx, fractal->win);
        draw(fractal, fractal->colors);
    }
    return (0);
}

int	on_destroy_event(s_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
    mlx_destroy_window(fractal->mlx, fractal->win);
    exit(1);
}

int	print_key(int key)
{
	printf("%d\n", key);
	return (1);
}

int main(void)
{
	s_fractal	*fractal;

	fractal = malloc(sizeof(s_fractal));

	color *color1 = (color *)malloc(sizeof(color));
	color *color2 = (color *)malloc(sizeof(color));
	color *color3 = (color *)malloc(sizeof(color));

	color1->color_b = 0xa958c4;
	color1->next = color2;
	color2->color_b = 0xe6c477;
	color2->next = color3;
	color3->color_b = 0x58ed45;
	color3->next = color1;

	fractal->zoom = 1.0;
	fractal->start_x = 0;
	fractal->start_y = 0;
	fractal->colors = color1;

	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		return (MLX_ERROR);
	fractal->win = mlx_new_window(fractal->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fract-ol");
	fractal->img = mlx_new_image(fractal->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);

	draw(fractal, fractal->colors);
	
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
	mlx_key_hook(fractal->win, print_key, &fractal);
    mlx_hook(fractal->win, 17, 0, on_destroy_event, &fractal);
	mlx_loop(fractal->mlx);

}

 // utliser chatgpt pour m accompagne a faire ce projet, lui demander avec l outil web de m aider a aprtir de cette page : https://medium.com/@leogaudin/fract-ol-creating-graphically-beautiful-fractals-6664b6b045b5
 // bien comprendre le principe de nomnbre complexe
 
