/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:33:02 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/21 02:21:53 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(int n, int sign)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	if (sign < 0)
		len++;
	return (len);
}

static int	ft_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

int	ft_max_itoa(t_printf *d)
{
	d->f_print = ft_strdup("-2147483648");
	if (!d->f_print)
		return (0);
	return (1);
}

int	ft_itoa_printf(t_printf *d, int n)
{
	int		sign;
	int		len;

	if (n == -2147483648)
		ft_max_itoa(d);
	sign = ft_sign(n);
	if (sign < 0)
		n *= -1;
	len = ft_num_len(n, sign);
	d->f_print_l = len;
	d->f_print = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!d->f_print)
		return (0);
	while (len--)
	{
		if (len == 0 && sign < 0)
			d->f_print[len] = '-';
		else
		{
			d->f_print[len] = '0' + (n % 10);
			n /= 10;
		}
	}
	ft_print_num(d);
	return (1);
}
