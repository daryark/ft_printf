/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 03:33:19 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/27 01:16:42 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_s(t_printf *d, char *s)
{
	if (!s)
		s = "(null)";
	d->f_print_l = ft_strlen(s);
	write (1, s, d->f_print_l);
	d->len_printed += d->f_print_l;
}

	// ft_print_out(d);

// int	ft_print_s(t_printf *d, char *s)
// {
// 	// char	*str;

// 	// str = ft_strdup(s);
// 	// if (!str)
// 	// 	return (0);
// 	// d->f_print = str;
// 	if (!*s)
// 			s = "(null)";
// 	d->f_print_l = ft_strlen(s);
// 	// while (*s)
// 	// {
// 		write (1, s, ft_strlen(s));
// 	// 	s++;
// 	// }
// 	// ft_print_num(d);
// 	return (1);
// }