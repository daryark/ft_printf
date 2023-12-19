/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:49:07 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/19 19:40:38 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// data->base_arr = {"0123456789", "01234567abcdef", "01234567ABCDEF"};
int	ft_format_checker(t_printf *data, va_list args)
{
	char	*s;

	s = data->curr_s;
	printf("curr: %c\n", *s);
	printf("args: %d\n", va_arg(args, int));
	if (*s == 'd' || *s == 'i' || *s == 'u' || *s == 'x'
		|| *s == 'X' || *s == 's' || *s == 'c' || *s == '%'
		|| *s == 'p')
	{
		if (*s == 'd' || *s == 'i')
			ft_itoa_printf(data, va_arg(args, int));
		else if (*s == 'u' || *s == 'x' || *s == 'X')
			ft_utoa_base(data, va_arg(args, unsigned));
		// else if (*s == 'p')
		// 	ft_print_ptr(va_arg(args, void *), &s);
		// else if (*s == 's')
		// 	data->print = va_arg(args, char *);
		// else if (*s == 'c' || *s == '%')
		// 	data->print = va_arg(args, char);
		// else
		// 	return (1);
		ft_print_format(data);
		data->curr_s++;
	}
	return (0);
}
