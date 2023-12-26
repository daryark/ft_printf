/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:23:43 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/24 17:44:21 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags	*ft_define_flags(void)
{
	t_flags		*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	return (ft_reset_flags(flags));
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
	data->start_p = str;
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

void	*ft_define_base(t_printf *d)
{
	t_base	*s_base;

	s_base = malloc(sizeof(t_base));
	if (!s_base)
		return (NULL);
	s_base->b_l = 10;
	if (*d->curr_s == 'u' || *d->curr_s == 'i' || *d->curr_s == 'd')
		s_base->base = "0123456789";
	else
	{
		if (*d->curr_s == 'X')
			s_base->base = "0123456789ABCDEF";
		else
			s_base->base = "0123456789abcdef";
		s_base->b_l = 16;
	}
	return (s_base);
}
