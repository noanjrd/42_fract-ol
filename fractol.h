/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:19:29 by njard             #+#    #+#             */
/*   Updated: 2025/01/16 18:17:13 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <math.h>

#include "ft_printf/ft_printf.h"
#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 400


typedef struct	s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int	number;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
    double  zoom;
    double     start_x;
    double     start_y;
    double c_re;
    double c_i;
	int	adress;
}				s_fractal;

# define oneline "|--------------------------------------------------------------------|\n"
# define twoline "| Here are all the fractals avalable :                               |\n"
# define threeline "|                                                                    |\n"
# define fourline "|     -Julia                                                         |\n"
# define fiveline "|     -Mandelbrot                                                    |\n"
# define sixline "|                                                                    |\n"
# define sevenline "| Please enter your input into this form in the terminal :           |\n"
# define eightline "|                                                                    |\n"
# define nineline "| ./fractal <fractal name> <reel constant> <imaginary constant>      |\n"
# define tenline "|                                                                    |\n"
# define elevenline "|--------------------------------------------------------------------|\n"

int print_key(int key, s_fractal *fractal);
int	on_destroy_event(s_fractal *fractal);
void draw(s_fractal *fractal);
void key_pressure(s_fractal *fractal);
void	draw_julia(s_fractal *fractal);
void	draw_mandelbrot(s_fractal *fractal);
int	ft_atoi(const char *nptr);
void	malloc_color(s_fractal *fractal);

#endif