/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:42:19 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/07 20:17:38 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_unsigned_int_o(va_list *ap, char *tab)
{
	unsigned long long	x;
	int					len;
	int					ret;

	ft_flag_convert(ap, &tab, &x);
	len = ft_nbrlen_base(x, 8);
	ret = ft_cas_0(tab, x);
	if (ret != -1)
		return (ret);
	len += (int)tab[2];
	ret = ft_ret(&tab, len);
	ft_fill_size_min(&tab, len);
	ft_fill_precision(&tab, len);
	ft_putull_base(x, 8);
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
