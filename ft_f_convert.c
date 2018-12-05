/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 08:57:28 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/05 17:08:44 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_int(va_list *ap, char tab[8])
{
	int 	x;

	x = va_arg(*ap, long long);
	i = 0;
	if (tab[0] == 1)
	{
		x = -x;
		ft_putchar('-');
	}
	if (tab[1] == 1)
		ft_putchar('+');
	if (tab[0] == 1)
		ft_putchar('-');
	if (tab[4] == 1)
		ft_putchar(' ');
	if (tab[5] >= ft_nbr_len(x, 10) && tab[6] == 0)
	{
		if (!(str = (char*)malloc(sizeof(str) * tab[5])))
			return (0);
		while (i < (int)tab[5] - ft_nbr_len(x, 10))
		{
			if (tab[3] == 1)
				ft_putchar('0');
			ft_putchar(' ');
			i++;
		}
	}
	if (tab[5] >= ft_nbr_len(x, 10) && tab[6] >= ft_nbr_len(x, 10))
	{
		while (tab[5] - tab[6] > 0)
		{
			ft_putchar(' ');
			tab[5] = tab[5] - 1;
		}
		while (tab[6] > ft_nbr_len(x, 10))
		{
			ft_putchar('0');
			tab[6] = tab[6] - 1;
		}
	}
	ft_put_ll(x);
	return (0);
}

int			ft_char_star(va_list *ap)
{
	char *s;

	s = va_arg(*ap, char *);
	ft_putstr(s);
	return (0);
}

int			ft_unsigned_int_o(va_list *ap)
{
	unsigned int x;

	x = va_arg(*ap, unsigned int);
	ft_putull_base(x , 2);
	return (0);
}

int		ft_char(va_list *ap, char tab[8])
{
	char	c;
	char	*str;
	int i;

	i = 0;
	c = (char)va_arg(*ap, int);
	if (tab[5] >= 1)
	{
		if (!(str = (char*)malloc(sizeof(str) * (tab[5] + 1))))
			return (0);
		while (i < (int)(tab[5]) - 1)
		{
			str[i] = ' ';
			i++;
		}
		str[i] = c;
		str[i + 1] = '\0';
	}
	ft_putstr(str);
	return (1);
}


