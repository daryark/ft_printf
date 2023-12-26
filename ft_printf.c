/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:34:56 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/26 05:27:19 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_arg(t_printf *d, va_list args)
{
	int	ok;

	ft_flags_checker(d);
	ok = ft_format_checker(d, args);
	ft_clean_used(d);
	return (ok);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	t_printf	*data;
	int			res;

	if (!s)
		return (-1);
	data = ft_define_struct(s);
	va_start(args, s);
	while (*data->curr_s)
	{
		if (*data->curr_s == '%')
		{
			data->curr_s++;
			if (!ft_print_arg(data, args))
				return (-1);
		}
		else
		{
			write(1, data->curr_s++, 1);
			data->len_printed++;
		}
	}
	va_end(args);
	res = data->len_printed;
	ft_clean(data);
	return (res);
}

// #include <limits.h>

int	main(void)
{
	int res1;
	int res2;
	int res3;
	int res4;
	char *s = "";

	// ft_printf("%%%c", 'x');
	res1 = printf(".%p.\n", NULL);
	res2 = ft_printf(".%p.\n", NULL);
	res3 = printf(".%p.\n", &s);
	res4 = ft_printf(".%p.\n", &s);
	printf("res1: %d\n, res2: %d\n, res3: %d\n, res4: %d\n", res1, res2, res3, res4);
// // 	int var1;
// // 	int var2;
// // 	int var3;
// // 	int var4;
// // 	int var5;
// // 	int var6;
// // 	int var7;
// // 	int var8;

// // 	printf("classic\n\n");	
// // 	var1 = printf(" %d \n", 0);
// // 	var2 = printf(" %d \n", -1);
// // 	var3 = printf(" %d \n", 1);
// // 	var4 = printf(" %d \n", 9);
// // 	var5 = printf(" %d \n", 10);
// // 	var6 = printf(" %d \n", 11);
// // 	var7 = printf(" %d \n", 15);
// // 	var8 = printf(" %d \n", 16);

// // 	printf("var1 =  %d \n", var1);
// // 	printf("var2 =  %d \n", var2);
// // 	printf("var3 =  %d \n", var3);
// // 	printf("var4 =  %d \n", var4);
// // 	printf("var5 =  %d \n", var5);
// // 	printf("var6 =  %d \n", var6);
// // 	printf("var7 =  %d \n", var7);
// // 	printf("var8 =  %d \n", var8);

// // 	printf("my test\n\n");

// // 	var1 = ft_printf(" %d \n", 0);
// // 	var2 = ft_printf(" %d \n", -1);
// // 	var3 = ft_printf(" %d \n", 1);
// // 	var4 = ft_printf(" %d \n", 9);
// // 	var5 = ft_printf(" %d \n", 10);
// // 	var6 = ft_printf(" %d \n", 11);
// // 	var7 = ft_printf(" %d \n", 15);
// // 	var8 = ft_printf(" %d \n", 16);

// // 	printf("var1 =  %d \n", var1);
// // 	printf("var2 =  %d \n", var2);
// // 	printf("var3 =  %d \n", var3);
// // 	printf("var4 =  %d \n", var4);
// // 	printf("var5 =  %d \n", var5);
// // 	printf("var6 =  %d \n", var6);
// // 	printf("var7 =  %d \n", var7);
// // 	printf("var8 =  %d \n", var8);
// // printf(" %d ", -1);
// // printf(" %d ", -9);
// // printf(" %d ", -10);
// // printf(" %d ", -11);
// // printf(" %d ", -14);
// // printf(" %d ", -15);
// // printf(" %d ", -16);
// // printf(" %d ", -99);

// 	int var1;
// 	int var2;
// 	int var3;
// 	int var4;
// 	int var5;
// 	int var6;
// 	int var7;
// 	int var8;

// 	printf("classic\n\n");	
// 	var1 = printf("%d", -1);
// 	var2 = printf("%d", -9);
// 	var3 = printf("%d", -10);
// 	var4 = printf("%d", -11);
// 	var5 = printf("%d", -14);
// 	var6 = printf("%d", -15);
// 	var7 = printf("%d", -16);
// 	var8 = printf("%d", -99);

// 	printf("var1 =  %d \n", var1);
// 	printf("var2 =  %d \n", var2);
// 	printf("var3 =  %d \n", var3);
// 	printf("var4 =  %d \n", var4);
// 	printf("var5 =  %d \n", var5);
// 	printf("var6 =  %d \n", var6);
// 	printf("var7 =  %d \n", var7);
// 	printf("var8 =  %d \n", var8);

// 	printf("my test\n\n");

// 	var1 = ft_printf("%d", -1);
// 	var2 = ft_printf("%d", -9);
// 	var3 = ft_printf("%d", -10);
// 	var4 = ft_printf("%d", -11);
// 	var5 = ft_printf("%d", -14);
// 	var6 = ft_printf("%d", -15);
// 	var7 = ft_printf("%d", -16);
// 	var8 = ft_printf("%d", -99);

// 	printf("var1 =  %d \n", var1);
// 	printf("var2 =  %d \n", var2);
// 	printf("var3 =  %d \n", var3);
// 	printf("var4 =  %d \n", var4);
// 	printf("var5 =  %d \n", var5);
// 	printf("var6 =  %d \n", var6);
// 	printf("var7 =  %d \n", var7);
// 	printf("var8 =  %d \n", var8);

// // // 	long long_min = LONG_MIN;
// // //     long long_max = LONG_MAX;
// // //     unsigned long ulong_max = ULONG_MAX;
// // //     unsigned long minus_ulong_max = -ULONG_MAX;
// // //     printf(" %p %p ", &long_min, &long_max);
// // //     printf(" %p %p \n", &ulong_max, &minus_ulong_max);
// // // 	ft_printf(" %p %p ", &long_min, &long_max);
// // //     ft_printf(" %p %p \n", &ulong_max, &minus_ulong_max);

// // // 	// printf("\n%%%c", 'x');

// // // // 	printf("u: .%#+ 15 0.8u.\n", 42);
// // // // 	ft_printf("u: .%#+ 15 0.8u.\n", 42);
// // // // 	printf("x: .%x.\n", 42);
// // // // 	ft_printf("x: .%x.\n", 42);
// // // // 	printf("X: .%X.\n\n", 42);
// // // // 	ft_printf("X: .%X.\n", 42);
// // // // // 	// printf("%")
// // // // // 	// printf(".%#.3 30-+0s, %s, %s, %s.\n", "hello", "", NULL, "-");
// // // // // 	// ft_printf(".%#.3 30-+0s, %s, %s.\n", "hello", " - ", NULL, "");
	return (0);
}
