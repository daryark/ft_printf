/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:09:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/20 19:44:53 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_num_len(unsigned int n, unsigned int b_l)
{
	unsigned int	len;

	len = 1;
	printf("n: %u\n", n);
	while (n >= b_l)
	{
		len++;
		n /= b_l;
	}
	return (len);
}

int	ft_utoa_base(t_printf *data, unsigned int n)
{
	char			*buf;
	unsigned int	len;
	t_base			*s_base;

	printf("number: %u", n);
	printf("hey");
	len = ft_num_len(n, s_base->b_l);
	data->f_print_l = len;
	s_base = ft_define_base(data);
	buf = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!buf || !s_base)
	{
		if (s_base)
			free(s_base);
		if (buf)
			free (buf);
		return (0);
	}
	while (len--)
	{
		printf("num: %c\n", s_base->base[n % s_base->b_l]);
		buf[len] = s_base->base[n % s_base->b_l];
		n /= s_base->b_l;
	}
	// ft_print_num(data);
	return (1);
}

// "0123456789abcdef"