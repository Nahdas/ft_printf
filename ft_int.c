/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:07:56 by alac              #+#    #+#             */
/*   Updated: 2018/12/11 21:49:54 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_size(long long x, char *tab, int *neg)
{
	int i;
	int mem;
	long long y;

	i = 0;
	if (x < 0)
		y = -x;
	if (tab[5] >= ft_nbrlen_base(y, 10) && tab[5] >= tab[6])
	{
		while (i < tab[5] - ft_nbrlen_base(y, 10) && i < tab[5] - tab[6])
		{
			if (tab[3] == 1)
			{
				if ((*neg) == 0 && i == 0 && x < 0)
				{
					(*neg) = (*neg) + 1;
					ft_putchar('-');
					x = -x;
					}
				if ((*neg) == -1 && i == 0 && x >= 0)
				{
					ft_putchar('+');
					(*neg) = (*neg) - 2;
				}
				ft_putchar('0');
			}
			else
			{
				if (x < 0)
					i++;
				ft_putchar(' ');
			}
			i++;
		}
	}
	mem = tab[5];
	if (tab[6] >= ft_nbrlen_base(x, 10) && tab[6] > tab[5])
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

static int		ft_precision(long long x, char *tab, int *neg)
{
	int mem;

	mem = tab[6];
	if ((*neg) == 0 && x < 0)
	{
		ft_putchar('-');
		(*neg) = 1;
		x = -x;
	}
	if (tab[1] == 1 && x >= 0 && (*neg) == -1)
	{
		ft_putchar('+');
		(*neg) = -2;
	}
	while (tab[6] > ft_nbrlen_base(x, 10))
	{
		ft_putchar('0');
		tab[6] = tab[6] - 1;
	}
	tab[6] = mem;
	return (0);
}

static int		ft_preceding_char(char *tab, long long x, int *neg)
{
	int i;

	i = 0;
	if (tab[1] == 1 && x >= 0)
	{
		tab[5]--;
		return (1);
	}
	if (tab[4] == 1 && tab[1] != 1 && x >= 0)
	{
		tab[5]--;
		ft_putchar(' ');
	}
	if (tab[0] == 1)
	{
		ft_precision(x, tab, neg);
		if (x < 0)
			x = -x;
		ft_putll_base(x, 10);
		return (-1);
	}
	return (0);
}

int		ft_int(va_list *ap, char *tab)
{
	long long 	x;
	int i;
	int neg;

	neg = 0;

	i = 0;
	if (tab[6] == 0 || !tab)
		return (0);
	ft_flag_convert_int(ap, &tab, &x);
	if (tab[1] == 1 && x >= 0)
		neg = -1;
	i = ft_preceding_char(tab, (long long)x, &neg);
	ft_size((long long)x, tab, &neg);
	if (i >= 0)
	{
		ft_precision((long long)x, tab, &neg);
		if (x < 0)
			x = -x;
		ft_putll_base((long long)x, 10);
	}
	else
		i = 0;
	if ((int)ft_nbrlen_base((long long)x, 10) > (int)tab[5] && (int)ft_nbrlen_base((long long)x, 10) > (int)tab[6])
		return (i + (int)ft_nbrlen_base((long long)x, 10));
	if ((int)tab[5] > (int)ft_nbrlen_base((long long)x, 10) && (int)tab[5] >= (int)tab[6])
		return (i + (int)tab[5]);
	return (i + (int)tab[6]);
}
