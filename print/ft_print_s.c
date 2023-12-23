/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 03:33:19 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/23 03:51:59 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_s(t_printf *d, char *s)
{
	char	*str;

	str = ft_strdup(s);
	if (!str)
		return (0);
	d->f_print = str;
	d->f_print_l = ft_strlen(s);
	ft_print_num(d);
	return (1);
}
