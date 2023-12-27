/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:42:01 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/27 00:41:13 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// static void	ft_set_value_c(t_printf *d, char *c)
// {
// 	// if (*d->curr_s == '%')
// 	// 	d->f_print = d->curr_s;
// 	// else
// 	// 	d->f_print = c;
// 	// d->f_print_l = 1;
// 	if (*d->curr_s == '%')
// 		write(1, d->curr_s, 1);
// 	else
// 		write(1, c, 1);
// 	d->len_printed++;
// }

void	ft_print_c(t_printf *d, int c)
{
	if (*d->curr_s == '%')
		write(1, "%", 1);
	else
		write(1, &c, 1);
	d->len_printed++;
}

	// ft_set_value_c(d, (char *)&c);
	// ft_print_out(d);
	// ft_reset_param(d);
