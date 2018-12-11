/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_convert_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:17:30 by alac              #+#    #+#             */
/*   Updated: 2018/12/11 16:02:00 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag_convert_int(va_list *ap, char **tab, long long	*x)
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
	if ((*tab)[6] == -1)
		(*tab)[6] = -1;
}

