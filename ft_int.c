/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:07:56 by alac              #+#    #+#             */
/*   Updated: 2018/12/06 14:42:15 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precision(long long x, char *tab)
{
	int i;

	i = 0;
	if (tab[5] >= ft_nbrlen_base(x, 10) && tab[6] == 0)
	{
		while (i < (int)tab[5] - ft_nbrlen_base(x, 10))
		{
			if (tab[3] == 1)
				ft_putchar('0');
			ft_putchar(' ');
			i++;
		}
	}
	if (tab[6] >= ft_nbrlen_base(x, 10))
	{
		while (tab[5] - tab[6] > 0)
		{
			ft_putchar(' ');
			tab[5] = tab[5] - 1;
		}
		while (tab[6] > ft_nbrlen_base(x, 10))
		{
			ft_putchar('0');
			tab[6] = tab[6] - 1;
		}
	}
	return (0);
}

int		ft_preceding_char(char *tab)
{
	if (tab[1] == 1)
		ft_putchar('+');
	if (tab[0] == 1)
		ft_putchar('-');
	if (tab[4] == 1)
		ft_putchar(' ');
	return (0);
}

int		ft_int(va_list *ap, char *tab)
{
	long long 	x;

	if (!tab)
		return (0);
	x = va_arg(*ap, long long);
	ft_preceding_char(tab);
	ft_precision(x, tab);
	ft_putll_base(x, 10);
	return (0);
}
