/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:52:17 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/05 14:00:49 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char		*ft_creat_tab(void)
{
	char *tab;
	int i;

	if (!(tab = (int*)malloc(sizeof(int) * 8)))
		return (0);
	i = 0;
	ft_bzero(tab, 8);
	return (tab);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	char 		*tab;
	t_list_f	*list;
	t_list_f	*head;
	int			i;

	i = 0;
	list = NULL;
	head = NULL;
	va_start(ap, format);
	list = ft_make_list_f();
	tab = ft_creat_tab();
	if (!(head = (t_list_f*)malloc(sizeof(t_list_f))))
		return (0);
	while(format[i])
	{
		head = list;
		if (format[i] == '%')
		{
			i = ft_capture_the_flag(&tab, format, i);
			while (head && !ft_strcmp_modif(&format[i], head->s))
				head = head->next;
			(head->f)(&ap, tab);
			i++;
		}
		ft_bzero(tab, 8);
		write(1, &format[i++], 1);
	}
	va_end(ap);
	return (0);
}

int		main()
{
	ft_printf("int = %d\nstring = %s\noctal = %o\n", 42, "BONJOUR", (unsigned int)42000);
	return (0);
}
