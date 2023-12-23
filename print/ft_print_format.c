/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:45:36 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/23 04:21:50 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//amnt of 0 to be printed before nbr
//if nb is neg, add one more 0, but one less width space
void	ft_len_dots(t_printf *d)
{
	if (d->f_print[0] == '-' && (*d->curr_s == 'd' || *d->curr_s == 'i'))
	{
		d->f_print_l--;
		d->flags->width--;
	}
	if (*d->curr_s == 's')
	{
		if (d->flags->dot < d->f_print_l)
			d->f_print_l = d->flags->dot;
		d->flags->dot = 0;
	}
	else if (d->flags->dot > d->f_print_l
		&& *d->curr_s != 'c' && *d->curr_s != '%')
		d->flags->dot -= d->f_print_l;
	else
		d->flags->dot = 0;
}

int	ft_hash_amnt(t_printf *d)
{
	if (((*d->curr_s == 'x' || *d->curr_s == 'X') && d->flags->hash)
		|| *d->curr_s == 'p')
		return (2);
	else
		d->flags->hash = 0;
	return (0);
}

//if need to print + or " " before nbr
int	ft_positive_ident(t_printf *d)
{
	if (d->f_print[0] != '-' && (*d->curr_s == 'd' || *d->curr_s == 'i'))
	{
		if (d->flags->plus)
			d->flags->space = 0;
		if (d->flags->plus || d->flags->space)
			return (1);
	}
	d->flags->space = 0;
	d->flags->plus = 0;
	return (ft_hash_amnt(d));
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
}

void	ft_fill_char(char c, int n)
{
	while (n)
	{
		write(1, &c, 1);
		n--;
	}
}
