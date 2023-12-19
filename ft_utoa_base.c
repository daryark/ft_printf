/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:09:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/19 20:18:42 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_base	ft_define_base(t_printf *data)
{
	t_base	*s_base;

	s_base = malloc(sizeof(t_base));
	if (!s_base)
		return (NULL);
	s_base->b_l = 10;
	if (*data->curr_s == 'u')
		s_base->base = "0123456789";
	else
	{
		if (*data->curr_s == 'x')
			s_base->base = "01234567abcdef";
		else
			s_base->base = "01234567ABCDEF";
		s_base->b_l = 16;
	}
	return (s_base);
}

static unsigned int	ft_num_len(unsigned int n, unsigned int b_l)
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

void	ft_utoa_base(t_printf *data, unsigned int n)
{
	char			*buf;
	unsigned int	len;
	t_base			*s_base;

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
		return (NULL);
	}
	while (len--)
	{
		printf("length: %d\n", len);
		buf[len] = s_base->base[n % s_base->b_l];
		n /= s_base->b_l;
	}
}
