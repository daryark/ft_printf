/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:24:39 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/26 02:30:45 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

//!delete it later
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
	int	negative;
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
void		*ft_define_base(t_printf *d);

void		ft_flags_checker(t_printf *d);
int			ft_format_checker(t_printf *d, va_list args);

int			ft_print_d_i(t_printf *d, int n);
// int			ft_utoa_base(t_printf *d, unsigned int n);
void		ft_utoa_base(unsigned long n, t_base *b);
// void		ft_print_u_x(t_printf *d);
unsigned int	ft_u_num_len(unsigned int n, unsigned int b_l);
int	ft_print_u_x(t_printf *d, unsigned int n);
void	ft_hash_ident(t_printf *d);
int	ft_hash_amnt(t_printf *d);
int			ft_print_ptr(t_printf *d, void *p);
int			ft_print_c(t_printf *d, int c);
int			ft_print_s(t_printf *d, char *s);

void		ft_print_out(t_printf *d);

void		ft_total_print_l(t_printf *d);
void		ft_fill_char(char c, int n);

t_flags		*ft_reset_flags(t_flags *flags);
void		ft_reset_param(t_printf *d);
void		ft_clean_used(t_printf *d);
void		ft_clean(t_printf *d);
#endif