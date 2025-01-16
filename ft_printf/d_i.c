/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:47:02 by njard             #+#    #+#             */
/*   Updated: 2024/12/02 12:54:35 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	d_i(int i)
{
	char	*a;
	int		j;

	a = ft_itoa(i);
	j = 0;
	while (a[j])
	{
		write(1, &a[j], 1);
		j++;
	}
	free(a);
	return (j);
}
