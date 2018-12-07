/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_address.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:04:02 by alac              #+#    #+#             */
/*   Updated: 2018/12/07 13:21:39 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_p_address(va_list *ap, char *tab)
{
	void 		*x;
	int			i;

	i = 0;
	if (!tab)
		return (0);
	x = va_arg(*ap, void *);
	ft_putstr("0x");
	ft_putll_base((long long)x, 16);
	return (0);
}
