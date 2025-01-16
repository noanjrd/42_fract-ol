/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:16:00 by njard             #+#    #+#             */
/*   Updated: 2024/12/02 13:22:22 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	x_long(unsigned long nb)
{
	int		i;
	int		len;
	char	*base;
	char	*temp;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	temp = malloc(100);
	base = "0123456789abcdef";
	i = 0;
	while (nb > 0)
	{
		temp[i] = base[nb % 16];
		nb /= 16;
		i++;
	}
	len = i;
	temp[i--] = '\0';
	while (i >= 0)
		write(1, &temp[i--], 1);
	free(temp);
	return (len);
}

int	p(unsigned long nb)
{
	int	len;

	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len = 2;
	len += x_long(nb);
	return (len);
}
