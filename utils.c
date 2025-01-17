/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:46:10 by njard             #+#    #+#             */
/*   Updated: 2025/01/17 11:46:13 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_destroy_event(s_fractal **fractal)
{
	mlx_destroy_image((*fractal)->mlx, (*fractal)->img);
	mlx_destroy_window((*fractal)->mlx, (*fractal)->win);
    mlx_loop_end((*fractal)->mlx);
    mlx_destroy_display((*fractal)->mlx);
    free((*fractal)->adress);
    free((*fractal)->mlx);
	free(*fractal);
	exit(1);
}

int print_key(int key, s_fractal **fractal)
{
    if (key == 65363)
        (*fractal)->start_x += 0.1 * (*fractal)->zoom;
    if (key == 65361)
        (*fractal)->start_x -= 0.1 * (*fractal)->zoom;
    if (key == 65364)
        (*fractal)->start_y += 0.1 * (*fractal)->zoom;
    if (key == 65362)
        (*fractal)->start_y -= 0.1 * (*fractal)->zoom;
    if (key == 65307)
		on_destroy_event(fractal);
    if (key == 'q')
		(*fractal)->c_i += 0.01;
    if (key == 'w')
		(*fractal)->c_i -= 0.01;
    if (key == 'a')
		(*fractal)->c_re += 0.01;
    if (key == 's')
		(*fractal)->c_re -= 0.01;
    if (key == 'i')
		(*fractal)->iteration += 50;
    draw(fractal);
    return (0);
}

int mouse_hook(int button, int x, int y, void **param)
{
    s_fractal **fractal = (s_fractal **)param;

    x = 0;
    y = 0;
    if (button == 5 )
        (*fractal)->zoom *= 1.1;
    else if (button == 4 )
        (*fractal)->zoom *= 0.9;
    draw(fractal);
    return (0);
}

void malloc_color(s_fractal **fractal)
{
    (*fractal)->adress = malloc(sizeof(int));
    if (!(*fractal)->adress)
        return ;
    uintptr_t raw_address = (uintptr_t)(*fractal)->adress;
    *((*fractal)->adress) = raw_address ;
}


void key_pressure(s_fractal **fractal)
{
	mlx_hook((*fractal)->win, 6, KeyPressMask, mouse_hook, fractal);
	mlx_mouse_hook((*fractal)->win, mouse_hook, fractal);
	mlx_key_hook((*fractal)->win, print_key, fractal);
    mlx_hook((*fractal)->win, 17, 0, on_destroy_event, fractal);
	mlx_loop((*fractal)->mlx);
}