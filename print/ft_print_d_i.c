/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:26:49 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/22 00:31:41 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_d_i(t_printf *d, int n)
{
	if (!ft_itoa_printf(d, n))
		return (0);
	ft_print_num(d);
	return (1);
}
