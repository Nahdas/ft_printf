/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:52:17 by lmariott          #+#    #+#             */
/*   Updated: 2018/12/13 16:38:29 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

char			*ft_creat_tab(void)
{
	char	*tab;
	int		i;

	if (!(tab = (char *)malloc(sizeof(char) * 8)))
		return (0);
	i = 0;
	ft_bzero(tab, 8);
	tab[6] = -1;
	return (tab);
}

void			ft_init_part_printf(char **tab, int **var)
{
	*tab = ft_creat_tab();
	if (!(*var = (int*)malloc(sizeof(int) * 2)))
		return ;
	(*var)[0] = -1;
	(*var)[1] = 0;
}

int				ft_printf_part(const char *format, t_list_f *head,
		t_list_f *list, va_list *ap)
{
	char		*tab;
	int			*var;

	ft_init_part_printf(&tab, &var);
	while (format[++var[0]])
	{
		head = list;
		if (format[var[0]] == '%')
		{
			var[0] = ft_capture_the_flag(&tab, format, &var);
			if (format[var[0]] == '\0')
				return (var[0] + var[1] + 1);
			while (head && head->c != format[var[0]])
				head = head->next;
			if (head)
				var[1] += (head->f)(ap, tab);
			else
				var[1] += ft_any(format[var[0]], tab);
		}
		else
			write(1, &format[var[0]], 1);
	}
	ft_del_list_n_tab(list, &tab);
	return (var[0] + var[1]);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_list_f	*head;
	t_list_f	*list;
	int			ret;

	va_start(ap, format);
	list = NULL;
	head = NULL;
	list = ft_make_list_f();
	if (!(head = (t_list_f*)malloc(sizeof(t_list_f))))
		return (0);
	ret = ft_printf_part(format, head, list, &ap);
	va_end(ap);
	free(head);
	return (ret);
}
/*
int		main()
{
	int i;
	int j;


	i = 0;
	j = 0;
	i = ft_printf("ok : %l#f\n", 42.42);
	j = printf("ok : %l#f\n", 42.42);
	printf("i :%d j :%d\n", i, j);
	return (0);
}*/
