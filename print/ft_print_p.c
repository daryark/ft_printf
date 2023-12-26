/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:43:53 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/26 17:36:19 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_ptr(t_printf *d, unsigned long long p)
{
	t_base	*s_base;

	s_base = ft_define_base(d);
	if (!s_base)
		return (0);
	ft_hash_ident(d);
	if (!p)
	{
		write (1, "0", 1);
		d->f_print_l += 1;
	}
	else
	{
		d->f_print_l += ft_u_num_len(p, s_base->b_l);
		ft_utoa_base(p, s_base);
	}
	free(s_base);
	d->len_printed += d->f_print_l + 2;
	return (1);
}
