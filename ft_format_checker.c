/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:49:07 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/21 02:07:31 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// data->base_arr = {"0123456789", "01234567abcdef", "01234567ABCDEF"};
int	ft_format_checker(t_printf *data, va_list args)
{
	char	*s;
	int		ok;
	unsigned int i;

	s = data->curr_s;
	if (*s == 'd' || *s == 'i' || *s == 'u' || *s == 'x'
		|| *s == 'X' || *s == 's' || *s == 'c' || *s == '%'
		|| *s == 'p')
	{
		if (*s == 'd' || *s == 'i')
		{
			ok = ft_itoa_printf(data, va_arg(args, int));
			// printf("ok: %d\n", ok);
			// printf("data->f_print_l %d\n", data->f_print_l);
			// printf("data->f_print %s\n", data->f_print);
		}
		// else 
		// if (*s == 'u' || *s == 'x' || *s == 'X')
		// {
		// 	i = va_arg(args, unsigned int);
		// 	printf("args: %u\n", i);
		// 	ok = ft_utoa_base(data, i);
		// }
		// else if (*s == 'p')
		// 	ft_print_ptr(va_arg(args, void *), &s);
		// else if (*s == 's')
		// 	data->print = va_arg(args, char *);
		// else if (*s == 'c' || *s == '%')
		// 	data->print = va_arg(args, char);
		// else
		// 	return (1);
		if (!ok)
			return (1);
		data->curr_s++;
	}
	else
		return (1);
	return (0);
}
