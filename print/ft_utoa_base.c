/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:09:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/26 02:30:32 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned int	ft_u_num_len(unsigned int n, unsigned int b_l)
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

void	ft_utoa_base(unsigned long n, t_base *b)
{
	if (n < b->b_l)
		write(1, &b->base[n], 1);
	else
	{
		ft_utoa_base((n / b->b_l), b);
		ft_utoa_base((n % b->b_l), b);
	}
}
