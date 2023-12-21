/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:49:07 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/21 03:20:03 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_checker(t_printf *data, va_list args)
{
	char	*s;
	int		ok;

	s = data->curr_s;
	ok = 0;
	if (*s == 'd' || *s == 'i' || *s == 'u' || *s == 'x'
		|| *s == 'X' || *s == 's' || *s == 'c' || *s == '%'
		|| *s == 'p')
	{
		if (*s == 'd' || *s == 'i')
			ok = ft_itoa_printf(data, va_arg(args, int));
		// else if (*s == 'u' || *s == 'x' || *s == 'X')
		// 	ok = ft_utoa_base(data, va_arg(args, unsigned int));
		// else if (*s == 'p')
		// 	ft_print_ptr(va_arg(args, void *), &s);
		// else if (*s == 's')
		// 	data->print = va_arg(args, char *);
		// else if (*s == 'c' || *s == '%')
		// 	data->print = va_arg(args, char);
		if (ok)
			data->curr_s++;
	}
	return (!ok);
}
