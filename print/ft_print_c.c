/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:42:01 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/14 23:48:20 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


void	ft_fill_char(char c, int n)
{
	while (n--)
		write(1, &c, 1);
}

#include <stdio.h>
void	ft_print_c(t_printf *d, int c)
{
	if (d->flags->width) //minus width for char itself
		d->flags->width--;
	if (d->flags->width && d->flags->zero && !d->flags->minus) //fill with zero-s
		ft_fill_char('0', d->flags->width);
	else if (d->flags->width && !d->flags->minus && !d->flags->zero) //fill with spaces
		ft_fill_char(' ', d->flags->width);
	if (*d->curr_s == '%')
		ft_fill_char('%', 1);
	else
		ft_fill_char(c, 1);
	if (d->flags->width && d->flags->minus) //fill with spaces from other side => if minus flag present
		ft_fill_char(' ', d->flags->width);
	d->len_printed += d->flags->width + 1;
	}
