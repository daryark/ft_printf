/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:04:07 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/27 01:06:29 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags	*ft_reset_flags(t_flags *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->dot = 0;
	flags->negative = 0;
	return (flags);
}

void	ft_reset_param(t_printf *d)
{
	d->f_print = NULL;
	d->f_print_l = 0;
}

void	ft_clean_used(t_printf *d)
{
	ft_reset_flags(d->flags);
	if (d->f_print)
		free(d->f_print);
	ft_reset_param(d);
}

void	ft_clean(t_printf *d)
{
	free(d->start_p);
	free(d->flags);
	free(d);
}
