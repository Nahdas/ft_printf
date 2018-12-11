/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:52:17 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/11 16:57:42 by alac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char		*ft_creat_tab(void)
{
	char *tab;
	int i;

	if (!(tab = (char *)malloc(sizeof(char) * 8)))
		return (0);
	i = 0;
	ft_bzero(tab, 8);
	tab[6] = -1;
	return (tab);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	char 		*tab;
	t_list_f	*list;
	t_list_f	*head;
	int			i;
	int			j;

	i = 0;
	list = NULL;
	head = NULL;
	va_start(ap, format);
	list = ft_make_list_f();
	tab = ft_creat_tab();
	j = 0;
	if (!(head = (t_list_f*)malloc(sizeof(t_list_f))))
		return (0);
	while (format[i])
	{
		head = list;
		if (format[i] == '%')
		{
			j += i;
			i++;
			i = ft_capture_the_flag(&tab, format, i);
			j -= i + 1;
			while (head && !ft_strcmp_modif(&format[i], head->s))
				head = head->next;
			if (!head)
				return (0);
			j += (head->f)(&ap, tab);
			i++;
		}
		ft_bzero(tab, 8);
		if (format[i] && format[i] != '%')
			write(1, &format[i++], 1);
	}
	va_end(ap);
	return (i + j);
}

int		main()
{
	int i;
	int j;


	i = 0;
	j = 0;
	i = ft_printf("% 5d\n", -42);
	j = printf("% 5d\n", -42);
	printf("i :%d j :%d\n", i, j);
	return (0);
}
