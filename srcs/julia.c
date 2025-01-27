/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:46:02 by njard             #+#    #+#             */
/*   Updated: 2025/01/27 16:26:57 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	calculate_julia_color(double z_x, double z_y, t_fractal *fractal)
{
	int		iteration;
	double	temp;
	int		result;

	iteration = 0;
	while ((z_x * z_x + z_y * z_y <= 4) && (iteration < fractal->iteration))
	{
		temp = z_x * z_x - z_y * z_y + fractal->c_re;
		z_y = 2.0 * z_x * z_y + fractal->c_i;
		z_x = temp;
		iteration++;
	}
	if (iteration == fractal->iteration)
		return (0x000000);
	result = iteration * (*fractal->adress);
	return (result);
}

static void	put_image(t_fractal **fractal)
{
	mlx_put_image_to_window((*fractal)->mlx, (*fractal)->win,
		(*fractal)->img, 0, 0);
	return ;
}

static void	init_value(t_fractal **fractal)
{
	(*fractal)->scale = WINDOW_WIDTH / ((*fractal)->zoom * 4);
	(*fractal)->z_x = 0;
	(*fractal)->z_y = 0;
	mlx_clear_window((*fractal)->mlx, (*fractal)->win);
}

void	draw_julia(t_fractal **fractal)
{
	int	color;
	int	new_y;
	int	new_x;

	new_y = 0;
	init_value(fractal);
	while (new_y < WINDOW_HEIGHT)
	{
		new_x = 0;
		while (new_x < WINDOW_WIDTH)
		{
			(*fractal)->z_x = (*fractal)->start_x + (new_x - WINDOW_WIDTH / 2)
				/ (*fractal)->scale;
			(*fractal)->z_y = (*fractal)->start_y + (new_y - WINDOW_HEIGHT / 2)
				/ (*fractal)->scale;
			color = calculate_julia_color((*fractal)->z_x,
					(*fractal)->z_y, *fractal);
			((int *)(*fractal)->addr)[new_y * WINDOW_WIDTH + new_x] = color;
			new_x++;
		}
		new_y++;
	}
	put_image(fractal);
}
