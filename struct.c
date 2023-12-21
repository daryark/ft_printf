/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:23:43 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/21 03:48:36 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_reset_flags(t_flags *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->dot = 0;
	return (flags);
}

void	ft_clean_used(t_printf *d)
{
	// free(d->f_print); //!!!what the heck with freeing it ????
	d->f_print = NULL;
	d->f_print_l = 0;
	ft_reset_flags(d->flags);
}

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

void	*ft_define_base(t_printf *data)
{
	t_base	*s_base;

	s_base = malloc(sizeof(t_base));
	if (!s_base)
		return (NULL);
	s_base->b_l = 10;
	if (*data->curr_s == 'u')
		s_base->base = "0123456789";
	else
	{
		if (*data->curr_s == 'x')
			s_base->base = "0123456789abcdef";
		else
			s_base->base = "0123456789ABCDEF";
		s_base->b_l = 16;
	}
	return (s_base);
}
