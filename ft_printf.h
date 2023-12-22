/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:24:39 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/22 01:07:40 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../1_libft/libft.h"

//! delete later
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include <inttypes.h>

#define MAGENTA "\033[35m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

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
	char	*start_p;
	int		len_printed;
	t_flags	*flags;
	char	*f_print;
	int		f_print_l;
}	t_printf;

int			ft_printf(const char *s, ...);

t_printf	*ft_define_struct(const char *s);
t_flags		*ft_define_flags(void);
t_flags		*ft_reset_flags(t_flags *flags);
void		*ft_define_base(t_printf *data);

void		ft_flags_checker(t_printf *d);
int			ft_format_print(t_printf *data, va_list args);

int			ft_print_d_i(t_printf *d, int n);
int			ft_itoa_printf(t_printf *d, int n);
int			ft_utoa_base(t_printf *d, unsigned int n);
void		ft_print_u_x(t_printf *d);

void		ft_print_format(t_printf *data);
void		ft_print_num(t_printf *data);

void		ft_clean_used(t_printf *d);
void		ft_clean(t_printf *d);
#endif