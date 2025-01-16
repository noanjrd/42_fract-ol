/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:58:55 by njard             #+#    #+#             */
/*   Updated: 2024/12/02 13:30:28 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		c(char chara);
int		s(char *chaine);
int		p(unsigned long nb);
int		d_i(int i);
int		ft_printf(const char *format, ...);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
int		u(unsigned int i);
int		x(unsigned int nb);
int		x_maj(unsigned int nb);

#endif