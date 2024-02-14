/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:04:07 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/14 22:50:34 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_reset_param(t_printf *d)
{
	// d->f_print = NULL;
	d->f_print_l = 0;
}

void	ft_clean_used(t_printf *d)
{
	ft_reset_flags(d->flags);
	// if (d->f_print)
	// 	free(d->f_print);
	ft_reset_param(d);
}

void	ft_clean(t_printf *d)
{
	free(d->start_p);
	free(d->flags);
	free(d);
}

// void	ft_clean_used(t_printf *d)
// {
// 	d->f_print = NULL;
// 	d->f_print_l = 0;
// }

// void	ft_clean(t_printf *d)
// {
// 	free(d->start_p);
// 	free(d);
// }
