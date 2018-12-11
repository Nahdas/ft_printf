/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:04:02 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/11 16:09:37 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_unsigned_int_u(va_list *ap, char *tab)
{
	unsigned long long	x;
	int					len;
	int					ret;

	ft_flag_convert(ap, &tab, &x);
	len = ft_nbrlen_base(x, 10);
	ret = ft_cas_0(tab, x);
	if (ret != -1)
	{
		if (tab[2] == 1)
			write(1, "0", 1);
		return (ret);
	}
	len += (int)tab[2];
	ret = ft_ret(&tab, len);
	ft_fill_size_min(&tab, len);
	ft_fill_precision(&tab,len);
	ft_putull_base(x , 10);
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
