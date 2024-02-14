/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:24:33 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/14 23:25:46 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_width(t_printf	*d)
{
	if (*(d->curr_s - 1) == '.')
		d->flags->dot = ft_atoi((const char *)d->curr_s);
	else
		d->flags->width = ft_atoi((const char *)d->curr_s);
	while (*(d->curr_s + 1) >= '0' && *(d->curr_s + 1) <= '9')
		d->curr_s++;
}

// #include <stdio.h>
void	ft_flags_checker(t_printf *d)
{
	while (*d->curr_s && (*d->curr_s == '+' || *d->curr_s == '-'
		|| *d->curr_s == ' ' || *d->curr_s == '.'
		|| *d->curr_s == '#' || (*d->curr_s >= '0' && *d->curr_s <= '9')))
	{
		if (*d->curr_s == '#')
			d->flags->hash = 1;
		else if (*d->curr_s == ' ')
			d->flags->space = 1;
		else if (*d->curr_s == '+')
			d->flags->plus = 1;
		else if (*d->curr_s == '.')
			d->flags->dot = 1;
		else if (*d->curr_s == '0')
			d->flags->zero = 1;
		else if (*d->curr_s == '-')
			d->flags->minus = 1;
		else if (*d->curr_s > '0' && *d->curr_s <= '9')
			ft_width(d);
		d->curr_s++;
	}
	// printf("hash: %d\nspace: %d\nplus: %d\ndot: %d\nzero: %d\nminus: %d\nwidth: %d\n", d->flags->hash, d->flags->space,d->flags->plus, d->flags->dot, d->flags->zero,d->flags->minus, d->flags->width);
}
