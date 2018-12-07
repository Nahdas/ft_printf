/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_address.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:04:02 by alac              #+#    #+#             */
/*   Updated: 2018/12/07 14:57:15 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_size(long long x, char *tab)
{
	int i;

	i = 0;
	if (tab[5] >= ft_nbrlen_base(x, 10))
	{
		while (i < (int)tab[5] - ft_nbrlen_base(x, 10) + 1)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (0);
}

static int		ft_preceding_char(char *tab, long long x)
{
	if (tab[0] == 1)
	{
		ft_putstr("0x");
		ft_putull_base_min((unsigned long long)x, 16);
		return (1);
	}
	return (0);
}

int				ft_p_address(va_list *ap, char *tab)
{
	void 		*x;
	int			i;

	i = 0;
	if (!tab)
		return (0);
	if (tab[6] == 0)
		return (0);
	if (tab[6] == -1)
		tab[6] = 1;
	x = va_arg(*ap, void *);
	i = ft_preceding_char(tab,(long long)x);
	ft_size((long long)x, tab);
	if (i != 1)
	{
		ft_putstr("0x");
		ft_putull_base_min((unsigned long long)x, 16);
	}
	if ((int)ft_nbrlen_base((long long)x, 10) > (int)tab[5])
		return ((int)ft_nbrlen_base((long long)x, 10)); 
	return  ((int)tab[5]);
}
