/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:43:53 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/27 00:13:00 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_ptr(t_printf *d, unsigned long long p)
{
	ft_hash_ident(d);
	if (!p)
	{
		write (1, "0", 1);
		d->len_printed += 1;
	}
	else
		ft_print_digits(d, p);
}
