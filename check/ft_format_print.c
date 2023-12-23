/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:49:07 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/23 03:51:47 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_format_print(t_printf *d, va_list args)
{
	char	*s;
	int		ok;

	s = d->curr_s;
	ok = 0;
	if (*s == 'd' || *s == 'i' || *s == 'u' || *s == 'x'
		|| *s == 'X' || *s == 's' || *s == 'c' || *s == '%'
		|| *s == 'p')
	{
		if (*s == 'd' || *s == 'i')
			ok = ft_print_d_i(d, va_arg(args, int));
		else if (*s == 'u' || *s == 'x' || *s == 'X')
			ok = ft_utoa_base(d, va_arg(args, unsigned int));
		else if (*s == 'p')
			ok = ft_print_ptr(d, va_arg(args, void *));
		else if (*s == 'c' || *s == '%')
			ok = ft_print_c(d, va_arg(args, int));
		else if (*s == 's')
			ok = ft_print_s(d, va_arg(args, char *));
		if (ok)
			d->curr_s++;
	}
	return (ok);
}
