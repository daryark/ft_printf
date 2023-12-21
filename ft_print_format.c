/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:45:36 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/21 02:35:11 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//? flags->zero, flags->hash

//amnt of 0 to be printed before nbr
void	ft_len_dots(t_printf *d)
{
	if (d->flags->dot > d->f_print_l)
	{
		d->flags->dot -= d->f_print_l;
	}
	else
		d->flags->dot = 0;
}

//if need to print + or " " before nbr
int	ft_positive_ident(t_printf *d)
{
	if (d->f_print[0] != '-')
	{
		if (d->flags->plus)
			d->flags->space = 0;
		if (d->flags->plus || d->flags->space)
			return (1);
	}
	d->flags->space = 0;
	d->flags->plus = 0;
	return (0);
	// if((d->f_print[0] != '-') && (d->flags->plus || d->flags->space))
	// 	return (1);
	// return (0);
}

//add len_printed and if need to print extra width length " "
void	ft_total_print_l(t_printf *d)
{
	int	ident;

	ident = ft_positive_ident(d);
	ft_len_dots(d);
	if (d->flags->width <= (d->f_print_l + d->flags->dot + ident))
		d->flags->width = 0;
	else
		d->flags->width -= (d->f_print_l + d->flags->dot + ident);
	d->len_printed += (d->f_print_l + d->flags->dot + d->flags->width + ident);

	// if (d->flags->width > (d->f_print_l + d->flags->dots + ft_positive_ident(d)))
	// {
	// 	d->len_printed += d->flags->width;
	// 	d->flags->width -= (d->f_print_l + d->flags->dots + ft_positive_ident(d));
	// }
	// else
	// {
	// 	d->flags->width = 0;
	// 	d->len_printed += (d->f_print_l + d->flags->dots + ft_positive_ident(d));
	// }
}

void	ft_printchar(char c, int n)
{
	while (n)
	{
		write(1, &c, 1);
		n--;
	}
}

void	ft_print_num(t_printf *d)
{
	ft_total_print_l(d);
	if (!d->flags->minus)
		ft_printchar(' ', d->flags->width);
	// printf("w: %d, p/s: %d, d: %d, n: %d, m: %d\n", d->flags->width, ft_positive_ident(d), d->flags->dot, d->f_print_l, d->flags->minus);
	write(1, "+", d->flags->plus);
	write(1, " ", d->flags->space);
	ft_printchar('0', d->flags->dot);
	write(1, d->f_print, d->f_print_l);
	if (d->flags->minus)
		ft_printchar(' ', d->flags->width);
}
