/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:02:39 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/13 18:53:22 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_checker(t_printf *data)
{
	t_flags	*flags;
	const char	*s;
	int		i;
	int		amnt;

	flags = data->flags;
	s = data->curr_s;
	i = 0;
	while (s[i] == '#' || s[i] == '+' || s[i] == '-'
		|| s[i] == '.' || (s[i] >= '0' && s[i] <= '9'))
	{
		if ((s[i + 1] > '0' && s[i + 1] <= '9') && !amnt)
			amnt = ft_atoi(&s[i + 1]);
		if (s[i] == '#' && !flags->hash)
			flags->hash = 1;
		else if (s[i] == ' ' && !flags->space && !flags->plus)
			flags->space = 1;
		else if (s[i] == '+' && !flags->plus)
			flags->plus[i] = 1;
		else if (s[i] == '-' && !flags->minus)
			flags->minus[i] = 1;
		else if (s[i] == '0')
			flags->zero = 1;
		else if (s[i] == '.')
		{
			if (amnt)
				flags->dot = amnt;
			else
				flags->dot = 1;
		}
		else if (amnt && s[i] != '.')
			flags->width = amnt;
		while (s[i + 1] >= '0' && s[i + 1] <= '9')
			i++;
		amnt = 0;
		i++;
	}
}

	// char	*all_flags;
	// int		i;
	// all_flags = "#-+ .0"
	// while (all_flags)
	// {
	// 	if(data->curr_s == '#')
	// 		flags->hash = 1;
	// }