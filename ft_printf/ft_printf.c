/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:54:10 by njard             #+#    #+#             */
/*   Updated: 2024/12/02 13:29:28 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(char letter, va_list args)
{
	int	len;

	len = 0;
	if (letter == 'c')
		len = c((char)va_arg(args, int));
	if (letter == 's')
		len = s(va_arg(args, char *));
	if (letter == 'd')
		len = d_i(va_arg(args, int));
	if (letter == 'i')
		len = d_i(va_arg(args, int));
	if (letter == 'u')
		len = u(va_arg(args, unsigned int));
	if (letter == 'x')
		len = x(va_arg(args, unsigned int));
	if (letter == 'X')
		len = x_maj(va_arg(args, unsigned int));
	if (letter == '%')
		len = c((char) '%');
	if (letter == 'p')
		len = p(va_arg(args, unsigned long));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			c(format[i]);
			len++;
		}
		if (format[i] == '%')
		{
			i++;
			len += check(format[i], args);
		}
		i++;
	}
	va_end(args);
	return (len);
}

// int	main()
// {
// 	// char i[20] = "coucouc vca va ";
// 	unsigned long	i;

// 	i = 4654553;
// 	int len;
// 	len = ft_printf("%lx", i);
// 	printf("\ntaille : %i\n", len);
// 	len = printf("%lx", i);
// 	printf("\n taille : %i", len);
// }
