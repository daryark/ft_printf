/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:24:39 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/19 20:35:43 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../1_libft/libft.h"

//! delete later
#include <stdio.h>

typedef struct s_flags
{
	int	plus;
	int	minus;
	int	zero;
	int	space;
	int	hash;
	int	dot;
	int	width;
}	t_flags;

typedef struct s_base
{
	char			*base;
	unsigned int	b_l;
}	t_base;

typedef struct s_printf
{
	char	*curr_s;
	int		len_printed;
	t_flags	*flags;
	char	*f_print;
	int		f_print_l;
}	t_printf;

int				ft_printf(const char *s, ...);
t_printf		*ft_define_struct(const char *s);
void			ft_flags_checker(t_printf *data);
int				ft_format_checker(t_printf *data, va_list args);
void			ft_itoa_printf(t_printf *data, int n);
void			*ft_utoa_base(t_printf *data, unsigned int n);
void			ft_print_format(t_printf *data);
#endif