/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:23:43 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/13 17:55:06 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*define_struct(const char *s)
{
	t_printf	*data;
	t_flags		*flags;

	data = malloc(sizeof(t_printf));
	if (!data)
		return (NULL);
	data->curr_s = s;
	data->len_printed = 0;
	flags = malloc(sizeof(t_flags));
	if (!flags)
	{
		free(data);
		return (NULL);
	}
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->dot = 0;
	data->flags = flags;
	return (data);
}
