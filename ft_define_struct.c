/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:23:43 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/19 19:41:18 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_define_flags(void)
{
	t_flags		*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->dot = 0;
	return (flags);
}

t_printf	*ft_define_struct(const char *s)
{
	t_printf	*data;
	char		*str;

	str = ft_strdup(s);
	data = malloc(sizeof(t_printf));
	if (!data || !str)
		return (NULL);
	data->curr_s = str;
	data->len_printed = 0;
	data->f_print = NULL;
	data->f_print_l = 0;
	data->flags = ft_define_flags();
	if (!data->flags)
	{
		free(data);
		return (NULL);
	}
	return (data);
}
