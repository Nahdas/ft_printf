/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_star.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alac <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:40:14 by alac              #+#    #+#             */
/*   Updated: 2018/12/12 17:29:29 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_print_str(char *s, char *tab, int len)
{
	int i;

	i = 0;
	while (i < len&& tab[6])
	{
		ft_putchar(s[i]);
		i++;
		(tab[6])--;
	}
}

static void			ft_size(char *tab, int len)
{
	int i;
	int tmp;

	i = 0;
	tmp = (tab[6] > len ? len : tab[6]);
	while (tab[5] - i > tmp)
	{
		if (tab[3] == 0)
			write(1, " ", 1);
		if (tab[3] == 1)
			write(1, "0", 1);
		i++;
	}
}

int					ft_char_star(va_list *ap, char *tab)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	s = va_arg(*ap, char *);
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(s);
	if (tab[6] == -1)
		tab[6] = len;
	tab[7] = tab[6];
	if (tab[0] == 0)
		ft_size(tab, len);
	ft_print_str(s, tab, len);
	tab[6] = tab[7];
	if (tab[0] == 1)
		ft_size(tab, len);
	if (tab[7] < len)
		return (tab[7] > tab[5] ? tab[7] : tab[5]);
	else
		return (len > tab[5] ? len : tab[5]);
}
