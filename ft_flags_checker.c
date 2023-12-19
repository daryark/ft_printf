/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:02:39 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/19 20:17:08 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

static void	ft_width(t_printf	*data)
{
	char	*s;

	s = data->curr_s;
	if (*s == '.')
		data->flags->dot = ft_atoi((const char *)(s + 1));
	else
		data->flags->width = ft_atoi((const char *)(s + 1));
	while ((*s + 1) >= '0' && (*s + 1) <= '9')
		s++;
}

void	ft_flags_checker(t_printf *data)
{
	char	*s;

	s = data->curr_s;
	while (*s == '#' || *s == '+' || *s == '-'
		|| *s == '.' || (*s >= '0' && *s <= '9'))
	{
		if (*s == '#')
			data->flags->hash = 1;
		else if (*s == ' ')
			data->flags->space = 1;
		else if (*s == '+')
			data->flags->plus = 1;
		else if (*s == '0')
			data->flags->zero = 1;
		else if (*s == '-')
			data->flags->minus = 1;
		else if (*s == '.')
			data->flags->dot = 1;
		if ((*s + 1) > '0' && (*s + 1) <= '9')
			ft_width(data);
		s++;
	}
	printf("RES hash:%d, space:%d, plus:%d, minus:%d, zero:%d, dot:%d, width:%d\n", data->flags->hash, data->flags->space, data->flags->plus, data->flags->minus, data->flags->zero, data->flags->dot, data->flags->width);
}

	// char	*all_flags;
	// int		i;
	// all_flags = "#-+ .0"
	// while (all_flags)
	// {
	// 	if(data->curr_s == '#')
	// 		flags->hash = 1;
	// }