/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 23:11:52 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/26 03:40:29 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_u_x(t_printf *d, unsigned int n)
{
	t_base	*s_base;

	s_base = ft_define_base(d);
	if (!s_base)
		return (0);
	d->f_print_l = ft_u_num_len(n, s_base->b_l);
	ft_utoa_base((unsigned long)n, s_base);
	free(s_base);
	d->len_printed += d->f_print_l;
	return (1);
}
