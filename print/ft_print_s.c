/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 03:33:19 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/15 12:58:36 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_s(t_printf *d, char *s)
{
	if (!s)
		s = "(null)";
	d->f_print_l = ft_strlen(s);
	if (d->flags->dot >= 0 && d->flags->dot < d->f_print_l)
		d->f_print_l = d->flags->dot;
	if (d->flags->width > 0)
		d->flags->width -= d->f_print_l;
	if (d->flags->width <= 0)
		d->flags->width = 0;
	if (d->flags->width && d->flags->zero && !d->flags->minus) //fill with zero-s
		ft_fill_char('0', d->flags->width);
	else if (d->flags->width && !d->flags->minus && !d->flags->zero) //fill with spaces
		ft_fill_char(' ', d->flags->width);
	write (1, s, d->f_print_l);
	if (d->flags->width && d->flags->minus) //fill with spaces from other side => if minus flag present
		ft_fill_char(' ', d->flags->width);
	d->len_printed += d->f_print_l + d->flags->width;
}

//dot cut the amount
//number is the max width of filler (dot or zero-s)
//minus reverts the filler placement after the string