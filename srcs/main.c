/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:46:27 by njard             #+#    #+#             */
/*   Updated: 2025/01/27 15:25:38 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check_name_selection(char *argv, char *chaine)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (chaine[len])
		len++;
	while (argv[i])
		i++;
	if (i != len)
		return (0);
	i = 0;
	while (i < len)
	{
		if (argv[i] != chaine[i])
			return (0);
		i++;
	}
	return (1);
}

void	menu(int argc, char **argv, t_fractal **fractal)
{
	if (argc == 1)
	{
		instructions_display();
		free(*fractal);
		exit(1);
	}
	if (check_name_selection(argv[1], "Julia"))
		(*fractal)->number = 0;
	if (check_name_selection(argv[1], "Mandelbrot"))
		(*fractal)->number = 1;
	if (check_name_selection(argv[1], "Burning_ship"))
		(*fractal)->number = 2;
	if (argc >= 3)
		(*fractal)->c_re = ft_atoi(argv[2]);
	if (argc == 4)
		(*fractal)->c_i = ft_atoi(argv[3]);
	if ((*fractal)->number == 99)
	{
		instructions_display();
		free(*fractal);
		exit(1);
	}
}

void	draw(t_fractal **fractal)
{
	if ((*fractal)->number == 0)
		draw_julia(fractal);
	if ((*fractal)->number == 1)
		draw_mandelbrot(fractal);
	if ((*fractal)->number == 2)
		draw_burning_ship(fractal);
}

void	init_fractal(t_fractal **fractal)
{
	(*fractal)->number = 99;
	(*fractal)->c_re = -0.7;
	(*fractal)->c_i = 0.3;
	(*fractal)->zoom = 1.0;
	(*fractal)->start_x = 0;
	(*fractal)->start_y = 0;
	(*fractal)->iteration = 50;
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		exit(1);
	init_fractal(&fractal);
	menu(argc, argv, &fractal);
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Fract-ol");
	fractal->img = mlx_new_image(fractal->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img,
			&fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);
	malloc_color(&fractal);
	draw(&fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	key_pressure(&fractal);
}
