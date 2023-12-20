/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:02:39 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/20 22:20:24 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

static void	ft_width(t_printf	*data)
{
	printf("s: %c\n", *data->curr_s);
	if (*data->curr_s == '.')
		data->flags->dot = ft_atoi((const char *)(data->curr_s + 1));
	else
		data->flags->width = ft_atoi((const char *)(data->curr_s + 1));
	while ((*data->curr_s + 1) >= '0' && (*data->curr_s + 1) <= '9')
		data->curr_s++;
	printf("data->s: %c\n", *data->curr_s);
}

void	ft_flags_checker(t_printf *data)
{
	while (*data->curr_s == '#' || *data->curr_s == '+' || *data->curr_s == '-'
		|| *data->curr_s == '.' || (*data->curr_s >= '0' && *data->curr_s <= '9'))
	{
		if (*data->curr_s == '#')
			data->flags->hash = 1;
		else if (*data->curr_s == ' ')
			data->flags->space = 1;
		else if (*data->curr_s == '+')
			data->flags->plus = 1;
		else if (*data->curr_s == '0')
			data->flags->zero = 1;
		else if (*data->curr_s == '-')
			data->flags->minus = 1;
		else if (*data->curr_s == '.')
			data->flags->dot = 1;
		if ((*data->curr_s + 1) > '0' && (*data->curr_s + 1) <= '9')
		{
			printf("hey: %c\n", *data->curr_s);
			ft_width(data);
		}
		data->curr_s++;
	}
	printf("RES hash:%d, space:%d, plus:%d, minus:%d, zero:%d, dot:%d, width:%d\n", data->flags->hash, data->flags->space, data->flags->plus, data->flags->minus, data->flags->zero, data->flags->dot, data->flags->width);
}
