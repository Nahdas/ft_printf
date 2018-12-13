/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_convert_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:17:30 by alac              #+#    #+#             */
/*   Updated: 2018/12/13 14:20:50 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag_convert_int(va_list *ap, char **tab, long long *x)
{
	if ((*tab)[7] == 0)
		*x = va_arg(*ap, int);
	if ((*tab)[7] == 1)
		*x = (short)va_arg(*ap, int);
	if ((*tab)[7] == 3)
		*x = (char)va_arg(*ap, int);
	if ((*tab)[7] == 2)
		*x = va_arg(*ap, long);
	if ((*tab)[7] == 4)
		*x = va_arg(*ap, long long);
}

int			ft_return_int(char *tab, int len, int count)
{
	if (len > (int)tab[5] && len > (int)tab[6])
		return (len + count);
	if ((int)tab[5] >= len && (int)tab[5] > (int)tab[6])
		return ((int)tab[5] + count);
	return (count + (int)tab[6]);
}
