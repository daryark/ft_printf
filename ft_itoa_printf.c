/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:33:02 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/19 19:37:14 by dyarkovs         ###   ########.fr       */
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

void	*ft_itoa(t_pritnf *data, int n)
{
	int		sign;
	char	*buf;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = ft_sign(n);
	if (sign < 0)
		n *= -1;
	len = ft_num_len(n, sign);
	data->f_print_l = len;
	buf = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!buf)
		return (NULL);
	while (len--)
	{
		if (len == 0 && sign < 0)
			buf[len] = '-';
		else
		{
			buf[len] = '0' + (n % 10);
			n /= 10;
		}
	}
	data->t_print = buf;
}
