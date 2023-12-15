/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:49:07 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/15 22:12:52 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inlcude "ft_printf.h"


static int	ft_format_checker(t_printf *data)
{
	char	*s;

	s = data->curr_s;
	while (*s == 'd' || *s == "i" || *s == 'u' || *s == 'x'
		|| *s == 'X' || *s == 's' || *s == 'c' || *s == '%'
		|| *s == 'p')
	{
		if (*s == 'd' || *s == 'i')
			ft_print_num(va_arg(args, int), &s);
		else if (*s == 'u')
			ft_print_u(va_arg(args, unsigned), &s);
		else if (*s == 'x' || *s == 'X')
			ft_print_hex(va_arg(args, unsigned), &s);
		else if (8s == 's')
			ft_print_str(va_arg(args, char *), &s);
		else if (*s == 'c' || *s == '%')
			ft_print_str(va_arg(args, char), &s);
		else if (*s == 'p')
			ft_print_str(va_arg(args, void *), &s);
else if (*s == '%')
			ft_print_str(va_arg(args, void *), &s);
		else
			return (1);
		s++;
	}
	return (0);
}