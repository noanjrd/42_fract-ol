/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:19:29 by njard             #+#    #+#             */
/*   Updated: 2025/01/27 15:19:26 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../ft_printf/ft_printf.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include <math.h>
# include <stdint.h>
# include <stdlib.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 600

typedef struct t_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		number;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	start_x;
	double	start_y;
	double	c_re;
	double	c_i;
	int		*adress;
	int		iteration;
	double	z_x;
	double	z_y;
	double	scale;
}			t_fractal;
# define ONELINE_PART1 "|"
# define ONELINE_PART2 "----------------------------------------"
# define ONELINE_PART3 "--------------------------------------|\n"

# define TWOLINE_PART1 "| Here are all the fractals"
# define TWOLINE_PART2 " available :               "
# define TWOLINE_PART3 "                         |\n"

# define THREELINE_PART1 "|                          "
# define THREELINE_PART2 "                          "
# define THREELINE_PART3 "                          |\n"

# define FOURLINE_PART1 "|   -Julia                "
# define FOURLINE_PART2 "                          "
# define FOURLINE_PART3 "                           |\n"

# define FIVELINE_PART1 "|   -Mandelbrot           "
# define FIVELINE_PART2 "                          "
# define FIVELINE_PART3 "                           |\n"

# define FIVELINE2_PART1 "|   -Burning_ship         "
# define FIVELINE2_PART2 "                          "
# define FIVELINE2_PART3 "                           |\n"

# define SIXLINE_PART1 "|                          "
# define SIXLINE_PART2 "                          "
# define SIXLINE_PART3 "                          |\n"

# define SEVENLINE_PART1 "| Please enter your input "
# define SEVENLINE_PART2 "into this form in the "
# define SEVENLINE_PART3 "terminal :                     |\n"

# define EIGHTLINE_PART1 "|                          "
# define EIGHTLINE_PART2 "                          "
# define EIGHTLINE_PART3 "                          |\n"

# define TENLINE_PART1 "|   ./fract-ol <fractal "
# define TENLINE_PART2 "name> [reel constant] ["
# define TENLINE_PART3 "imaginary constant]             |\n"

# define TENLINE1_PART1 "| The real and imaginary "
# define TENLINE1_PART2 "constant are optional "
# define TENLINE1_PART3 "parameters for Julia set.       |\n"

# define TENLINE2_PART1 "| You can press i to add "
# define TENLINE2_PART2 "iterations.                "
# define TENLINE2_PART3 "                           |\n"

# define TENLINE3_PART1 "| You can also press q,w,a"
# define TENLINE3_PART2 " and s to change the "
# define TENLINE3_PART3 "parameters for Julia set.       |\n"

# define TENLINE4_PART1 "|                          "
# define TENLINE4_PART2 "                          "
# define TENLINE4_PART3 "                          |\n"

# define ELEVENLINE_PART1 "|"
# define ELEVENLINE_PART2 "---------------------------------------"
# define ELEVENLINE_PART3 "---------------------------------------|\n"

int			print_key(int key, t_fractal **fractal);
int			on_destroy_event(t_fractal **fractal);
void		draw(t_fractal **fractal);
void		key_pressure(t_fractal **fractal);
void		draw_julia(t_fractal **fractal);
void		draw_mandelbrot(t_fractal **fractal);
int			ft_atoi(const char *nptr);
void		malloc_color(t_fractal **fractal);
void		instructions_display(void);
void		draw_burning_ship(t_fractal **fractal);

#endif