/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:43:53 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/26 19:53:15 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_ptr(t_printf *d, unsigned long long p)
{
	ft_hash_ident(d);
	if (!p)
	{
		write (1, "0", 1);
		d->len_printed += 1;
	}
	else
		return (ft_print_digits(d, p));
	return (1);
}
