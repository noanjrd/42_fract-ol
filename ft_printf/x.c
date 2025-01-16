/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:57:30 by njard             #+#    #+#             */
/*   Updated: 2024/12/03 14:14:02 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x(unsigned int nb)
{
	int		i;
	int		len;
	char	*base;
	char	*temp;

	if (!nb)
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
