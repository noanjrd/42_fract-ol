/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:19:29 by njard             #+#    #+#             */
/*   Updated: 2025/01/27 15:55:31 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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
void		menu(int argc, char **argv, t_fractal **fractal);
void		init_fractal(t_fractal **fractal);

#endif