/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:45:36 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/20 22:05:09 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//? flags->zero, flags->hash
void	ft_print_num(t_printf *data)
{
	t_flags	*flags;

	flags = data->flags;
	if (flags->minus)
	{
		if (flags->plus || flags->space)
			data->len_printed++;
		if (flags->plus)
			write (1, "+", 1);
		else if (flags->space)
			write (1, " ", 1);
		if (flags->dot > data->f_print_l)
		{
			while (flags->dot > data->f_print_l)
			{
				write(1, "0", 1);
				data->len_printed++;
				flags->dot--;
			}
			write(1, data->f_print, data->f_print_l);
			if (flags->width > data->f_print_l)
			{
				write(1, " ", 1);
				data->len_printed++;
				flags-> width--;
			}
		}
	}
	data->len_printed += data->f_print_l;
}

	// if (flags->dot > data->f_print_l)
	// 	data->f_print_l += flags->dot;
	// if (flags->plus || flags->space)
	// 	data->f_print_l += 1;
	// if (flags->width > data->f_print_l)
	// {
	//     data->len_printed += data->f_print_l;
	//     if(flags->minus)
	// {

	// }
	// }