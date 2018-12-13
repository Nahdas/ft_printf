/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:31:36 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/13 15:34:07 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_uixmin_part(char **tab, int *ret, int *len, unsigned long long x)
{
	if ((*tab)[2] == 1 && x != 0)
	{
		*len += 2;
		if ((*tab)[3] == 1)
			write(1, "0x", 2);
	}
	*ret = ft_ret(tab, *len);
	ft_fill_size_min(tab, *len);
	if ((*tab)[2] == 1 && x != 0 && (*tab)[3] != 1)
		write(1, "0x", 2);
	(*tab)[2] = 0;
	ft_fill_precision(tab, *len, x);
}

int			ft_unsigned_int_x_min(va_list *ap, char *tab)
{
	unsigned long long	x;
	int					len;
	int					ret;

	ft_flag_convert(ap, &tab, &x);
	len = ft_unbrlen_base(x, 16);
	tab[7] = tab[2];
	tab[2] = 0;
	ret = ft_cas_0(tab, x);
	tab[2] = tab[7];
	if (ret != -1)
		return (ret);
	ft_uixmin_part(&tab, &ret, &len, x);
	ft_putull_base_min(x, 16);
	if (tab[0] == 1)
		while (tab[5] > tab[7] && tab[5] > len)
		{
			tab[5]--;
			write(1, " ", 1);
		}
	return (ret);
}
