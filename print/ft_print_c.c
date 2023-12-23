/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:42:01 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/23 03:27:02 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_set_value_c(t_printf *d, char *c)
{
	if (*d->curr_s == '%')
		d->f_print = d->curr_s;
	else
		d->f_print = c;
	d->f_print_l = 1;
}

int	ft_print_c(t_printf *d, int c)
{
	ft_set_value_c(d, (char *)&c);
	ft_print_num(d);
	ft_reset_param(d);
	return (1);
}
