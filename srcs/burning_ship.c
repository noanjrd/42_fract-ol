/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:34:43 by njard             #+#    #+#             */
/*   Updated: 2025/01/27 15:47:07 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	calculate_burning_ship_color(t_fractal *fractal)
{
	int		iteration;
	double	temp;
	int		result;
	double	z_y;
	double	z_x;

	iteration = 0;
	z_x = 0;
	z_y = 0;
	while ((z_x * z_x + z_y * z_y <= 4) && (iteration < fractal->iteration))
	{
		z_x = fabs(z_x);
		z_y = fabs(z_y);
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

void	draw_burning_ship(t_fractal **fractal)
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
			(*fractal)->c_re = (*fractal)->start_x + (new_x - WINDOW_WIDTH / 2)
				/ (*fractal)->scale;
			(*fractal)->c_i = (*fractal)->start_y + (new_y - WINDOW_HEIGHT / 2)
				/ (*fractal)->scale;
			color = calculate_burning_ship_color(*fractal);
			((int *)(*fractal)->addr)[new_y * WINDOW_WIDTH + new_x] = color;
			new_x++;
		}
		new_y++;
	}
	put_image(fractal);
}
