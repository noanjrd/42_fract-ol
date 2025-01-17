/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:46:02 by njard             #+#    #+#             */
/*   Updated: 2025/01/17 11:48:52 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_julia_color(double z_x, double z_y, s_fractal *fractal)
{
	int iteration;
	double temp;
	int result;

	iteration = 0;
	while ((z_x * z_x + z_y * z_y <= 4) && (iteration < fractal->iteration))
	{
		temp = z_x * z_x - z_y * z_y + fractal->c_re; 
		z_y = 2.0 * z_x * z_y + fractal->c_i;
		z_x = temp;
		iteration++;
	}
	if (iteration == fractal->iteration)
		return 0x000000;
	result = iteration * *(fractal->adress);
	return (result);
}

void	draw_julia(s_fractal **fractal)
{
	int	new_y = 0;
	int	new_x = 0;
	double z_x = 0;
    double z_y = 0;
    double scale = WINDOW_WIDTH / ((*fractal)->zoom * 4); 
	int color;

	mlx_clear_window((*fractal)->mlx, (*fractal)->win);
    while (new_y < WINDOW_HEIGHT)
    {
        new_x = 0;
        while (new_x < WINDOW_WIDTH)
        {
            z_x = (*fractal)->start_x +  (new_x - WINDOW_WIDTH / 2) / scale;
            z_y = (*fractal)->start_y + (new_y - WINDOW_HEIGHT / 2) / scale;
            color = calculate_julia_color(z_x, z_y, *fractal);
            ((int *)(*fractal)->addr)[new_y * WINDOW_WIDTH + new_x] = color;
            new_x++;
        }
        new_y++;
    }
    mlx_put_image_to_window((*fractal)->mlx, (*fractal)->win, (*fractal)->img, 0, 0);
}

