/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:07:56 by alac              #+#    #+#             */
/*   Updated: 2018/12/07 17:25:35 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_size(long long x, char *tab)
{
	int i;
	int mem;

	i = 0;
	if (tab[5] >= ft_nbrlen_base(x, 10) && tab[5] >= tab[6] && tab[6] < 2)
	{
		while (i < (int)tab[5] - ft_nbrlen_base(x, 10))
		{
			if (tab[3] == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
	}
	mem = tab[5];
	if (tab[6] >= ft_nbrlen_base(x, 10))
	{
		while (tab[5] - tab[6] > 0)
		{
			ft_putchar(' ');
			tab[5] = tab[5] - 1;
		}
	}
	tab[5] = mem;
	return (0);
}

static int		ft_precision(long long x, char *tab)
{
	int mem;
	mem = tab[6];
	while (tab[6] > ft_nbrlen_base(x, 10))
	{
		ft_putchar('0');
		tab[6] = tab[6] - 1;
	}
	tab[6] = mem;
	return (0);
}

static int		ft_preceding_char(char *tab, long long x)
{
	int i;

	i = 0;
	if (tab[1] == 1)
	{
		tab[5]--;
		return (1);
	}
	if (tab[4] == 1 && tab[1] != 1)
	{
		tab[5]--;
		ft_putchar(' ');
		i += 1;
	}
	if (tab[0] == 1)
	{
		ft_precision(x, tab);
		ft_putll_base(x, 10);
		return (-i);
	}
	return (0);
}

int		ft_int(va_list *ap, char *tab)
{
	long long 	x;
	int i;

	i = 0;
	if (tab[6] == 0)
		return (0);
	if (tab[6] == -1)
		tab[6] = 1;
	if (!tab)
		return (0);
	x = va_arg(*ap, long long);
	i = ft_preceding_char(tab, x);
	ft_size(x, tab);
	if (tab[1] == 1)
		ft_putchar('+');
	if (i >= 0)
	{
		ft_precision(x, tab);
		ft_putll_base(x, 10);
	}
	else
		i = -i;
	if ((int)ft_nbrlen_base((long long)x, 10) > (int)tab[5] && (int)ft_nbrlen_base((long long)x, 10) > (int)tab[6])
		return (i + (int)ft_nbrlen_base((long long)x, 10));
	if ((int)tab[5] > (int)ft_nbrlen_base((long long)x, 10) && (int)tab[5] >= (int)tab[6])
		return (i + (int)tab[5]);
	return (i + (int)tab[6]);
}
