/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 01:40:51 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/26 19:53:55 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_hash_ident(t_printf *d)
{
	if (ft_hash_amnt(d))
	{
		if (*d->curr_s == 'x' || *d->curr_s == 'p')
			write(1, "0x", 2);
		else if (*d->curr_s == 'X')
			write(1, "0X", 2);
		d->len_printed += 2;
	}
}

//evrth formated according to the res, just print
void	ft_print_out(t_printf *d)
{
	ft_total_print_l(d);
	if (!d->flags->minus)
	{
		if (*d->curr_s == 's' && d->flags->zero)
			ft_fill_char('0', d->flags->width);
		else
			ft_fill_char(' ', d->flags->width);
	}
	write(1, "+", d->flags->plus);
	write(1, " ", d->flags->space);
	if (d->flags->negative && (*d->curr_s == 'd' || *d->curr_s == 'i'))
		write(1, "-", 1);
	ft_hash_ident(d);
	ft_fill_char('0', d->flags->dot);
	write(1, d->f_print, d->f_print_l);
	// ft_format_checker(d, args);
	if (d->flags->minus)
		ft_fill_char(' ', d->flags->width);
}
//iterator is needed to not move the start pointer in case of negative number,
//cause need its address to free string.