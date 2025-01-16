/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:30:00 by njard             #+#    #+#             */
/*   Updated: 2025/01/07 19:15:34 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*n_egal_0(void)
{
	char	*tab;

	tab = malloc(2 * sizeof(char));
	if (!tab)
		return (NULL);
	tab[0] = '0';
	tab[1] = '\0';
	return (tab);
}

static int	get_number_of_places(long nb)
{
	int	place;

	place = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		place += 1;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		place += 1;
	}
	return (place);
}

static char	*allocate_tab(int place)
{
	char	*tab;

	tab = malloc((place + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	tab[place] = '\0';
	return (tab);
}

static void	fill_tab(char *tab, long nb, int place, int signe)
{
	while (place >= 0)
	{
		tab[place] = ((nb % 10) + '0');
		nb /= 10;
		if (signe == -1 && place == 0)
			tab[0] = '-';
		place--;
	}
}

char	*ft_itoa_u(unsigned int n)
{
	long	nb;
	char	*tab;
	int		place;
	int		signe;

	nb = (long)n;
	if (n == 0)
		return (n_egal_0());
	signe = 1;
	place = get_number_of_places(nb);
	nb *= signe;
	tab = allocate_tab(place);
	if (!tab)
		return (NULL);
	fill_tab(tab, nb, place - 1, signe);
	return (tab);
}

// int main()
// {
//     int nb = 10000;
//     ft_itoa(nb);
// }