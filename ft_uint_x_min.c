/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:31:36 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/07 19:36:11 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_unsigned_int_x_min(va_list *ap, char *tab)
{
	unsigned long long	x;
	int					len;
	int					ret;

	ft_flag_convert(ap, &tab, &x);
	len = ft_nbrlen_base(x, 16);
	tab[7] = tab[2];
	tab[2] = 0;
	ret = ft_cas_0(tab, x);
	tab[2] = tab[7];
	if (ret != -1)
		return (ret);
	if (tab[2] == 1 && x != 0)
	{
		len += 2;
		if (tab[3] == 1)
			write(1, "0x", 2);
	}
	ret = ft_ret(&tab, len);
	ft_fill_size_min(&tab, len);
	if (tab[2] == 1 && x != 0 && tab[3] != 1)
		write(1, "0x", 2);
	tab[2] = 0;
	ft_fill_precision(&tab, len);
	ft_putull_base_min(x , 16);
	if (tab[0] == 1)
	{
		while (tab[5] > tab[7] && tab[5] > len)
		{
			tab[5]--;
			write(1, " ", 1);
		}
	}
	return (ret);
}
