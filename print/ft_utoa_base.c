/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:09:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/22 01:08:47 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static unsigned int	ft_u_num_len(unsigned int n, unsigned int b_l)
{
	unsigned int	len;

	len = 1;
	while (n >= b_l)
	{
		len++;
		n /= b_l;
	}
	return (len);
}

int	ft_utoa_base(t_printf *d, unsigned int n)
{
	unsigned int	len;
	t_base			*s_base;

	s_base = ft_define_base(d);
	len = ft_u_num_len(n, s_base->b_l);
	d->f_print_l = len;
	d->f_print = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!d->f_print || !s_base)
	{
		if (s_base)
			free(s_base);
		if (d->f_print)
			free (d->f_print);
		return (0);
	}
	while (len--)
	{
		d->f_print[len] = s_base->base[n % s_base->b_l];
		n /= s_base->b_l;
	}
	ft_print_u_x(d);
	return (1);
}
