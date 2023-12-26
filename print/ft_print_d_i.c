/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:26:49 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/26 04:33:51 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_d_i(t_printf *d, int n)
{
	t_base	*s_base;
	long nb;

	nb = n;
	if (n < 0)
	{
		write (1, "-", 1);
		d->flags->negative = 1;
		d->f_print_l += 1;
		nb *= -1;
	}
	nb = (unsigned int)nb;
	s_base = ft_define_base(d);
	if (!s_base)
		return (0);
	d->f_print_l += ft_u_num_len(nb, s_base->b_l);
	ft_utoa_base(nb, s_base);
	free(s_base);
	d->len_printed += d->f_print_l;
	return (1);
}
