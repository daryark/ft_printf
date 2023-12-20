/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:34:56 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/20 22:05:27 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

#define MAGENTA "\033[35m"
#define BLUE "\033[34m"
#define RESET "\033[0m"


int	ft_printf(const char *s, ...)
{
	va_list		args;
	t_printf	*data;
	int			err;

	data = ft_define_struct(s);
	va_start(args, s);
	while (*data->curr_s)
	{
		if (*data->curr_s == '%')
		{
			data->curr_s++;
			ft_flags_checker(data);
			err = ft_format_checker(data, args);
			if (err)
				return (-1);
		}
		else
		{
			write(STDOUT_FILENO, BLUE, strlen(BLUE));  
			write(1, data->curr_s++, 1);
    		write(STDOUT_FILENO, RESET, strlen(RESET));
			data->len_printed++;
		}
	}
	va_end(args);
	// printf("data->len_printed %d\n", data->len_printed);
	return (data->len_printed);
}

// 
#include <string.h>
#include <stdio.h>
#include <limits.h>

#include <stdint.h>
#include <inttypes.h>

int    main(void)
{
	// int	res1;
	// int res2;
	ft_printf("ft_printf: %-10.6d\n", 3434);
	// printf(".%+-27.15-40p.\n", 3434);
	// printf(".%10+d,%+10d.\n", 4, 3);
	// printf("%030.10d\n", 89);
	// printf("ft_printf: %x\n", 3434);
	// printf("ft_printf: %x\n", 0xfff);
	// ft_printf("S%-+90.10.20.4dE\n", 45);
	// printf(MAGENTA"Native: S%-+90.10.20.4dE\n"RESET, 45);
	// printf(MAGENTA"Native: %D, %x, %S,\n"RESET, 23, 53, "lasdkf");
	// res1 = printf("S%-+30.10.20.4d%dE\n", 45);
	// res2 = printf("S%-+30.10.20.4d%dE\n", 45, "hkljdfkljs", 45);
	// printf("res1:%d\nres2:%d\n", res1, res2);

	// ft_printf("S%-+30.10.20.4d%dE\n", 45);
	// ft_printf("S%-+30.10.20.4d%dE\n", 45, "hkljdfkljs", 45);
	// printf(MAGENTA"Native: S%-+90.10.20.4DE\n"RESET, 45);
	// char	*s_test[20] = {"", " ", NULL, "hello", "hello\012newline", "hello\0nul", "hello\#flag", "nonprintables\v\f\b\t\a\\\r\'\n"};
	// long	d_test[20] = { -1, INT_MIN, INT_MAX, 0, 2.9, 2.0, -9.9, 0xff, 010, (INT_MAX + 1), (INT_MIN - 1)}

    // printf("Max unsigned int in decimal: %u\n", UINT_MAX);
    // printf("Max unsigned int in hex: %x\n", UINT_MAX);
// printf("S%.10xE", 45);
// printf("S%.10.xE", 45);
// printf("S%10.xE", 45);
// printf("S%10xE", 45);
// printf("S%5 19dE\n", 23);
// printf("S%# 0$\n");
// printf("S%# 0$\n", 32);
// printf("S%# 0q\n");
// printf("S%# 0q\n", 32);
// printf("S%# 0qq\n");

//*understand this fucking staff later
// printf("S%# 0qq$§¶§•¶ª657657dfdasf\n");
// printf("S%# 0qq657dfdasf$§¶§•¶ª\n");
// printf("S%# 0qq657qfdasf$§¶§•¶ª\n");
// printf("S%# 0q\n", 32, 33, 34);

// printf("S%10.5xE\n", 45);
// printf("S%.4xE\n", 45);
// printf("S%04xE\n", 45);

// printf("S%..10dE\n", 45);
// printf("S%..10sE\n", "its a very long string");
// printf("S%-+20..10.5.dE\n", 45);


	// printf("test:S%  -  8dE\n", 78);
	// printf("test:S%    -8dE\n", 78);
	// printf("test:S%    8dE\n", 78);

	// printf("S%#10xE\n", 0xff);
	// printf("S%010dE\n", 32);
	// printf("S%10.5dE\n", 32); //only dot flag can be after number, with the number fot the zeros to fill the space
	// printf("S%010.5dE\n", 32);
	// printf("S%010dE\n", 32);

   	// printf("%lu\n", strlen("hello\a\b\f\n\r\t\v\'\\"));
    // printf("%#f\n", 5.0);
    // printf("%d%d\n", 43434); //!more convertions than data type arguments
    // printf("%-d\n", 43434);
    // printf("%0d\n", 43434);
	// printf("%#d\n", 353543); //!flag '#' results in undefined behavior with 'd' conversion specifier
	// printf("%#s\n", "dlfjkds"); //!flag '#' results in undefined behavior with 's' conversion specifier
	// printf("%#-16f.\n", -353543.5);
	// // Right justification within 10 spaces
    // printf(".%10s.\n", "hello");
    // // Left justification within 10 spaces
    // printf(".%-10s.\n", "hello");
	// printf("%0 d\n", 353543);
	
	// printf("flags -30s: %-30send\n", "898");
	// printf("flags 30s: %30send\n", "898");
	// printf("flags -s: %-s\n", "898");
	// printf("flags (empty str) s:%send\n\n", "");
	// printf("len empty str: %d\n", printf("%s", ""));
	// printf("flags .: %.s\n", "str");
	// printf("flags .2: %.2send\n", "str");

	// printf("flags -30c: %-30cend\n", 'i');
	// printf("flags 30c: %30cend\n", 'i');
	// printf("flags -c: %-c\n\n", 'i');

	// printf("flags: %02d\n", 1);
	// printf("flags: %0d\n", 898);
	// printf("flags: %+d\n", 898);
	// printf("flags .: %.d\n", 898);
	// printf("flags " "20d: % 20d\n", 898);

////! "-" makes alignment of the whole text from the end, space takes place before the number. So if we aligned the text to the end - the space from the end of the row is considered as start(space before the nubmer)
	// printf("flags: st%- 10dend\n", 897);
	// printf("flags: st% -10dend\n", 897);
	// printf("flags: st% 10dend\n", 897);
	// printf("flags: st%-10dend\n", 897);
	// printf("flags: st%10dend\n", 897);
	// printf("flags: st% 4dend\n", 897);

	// printf("flags: st% .0dend\n", 898);
	// printf("flags: st%.0dend\n", 898);
	// printf("flags: st%-10dend\n", 898);
	// printf("flags: st% .0dend\n", 898);
	// printf("flags: st%010dend\n", 898);
	// printf("flags: st%+.0dend\n", 898);
	// printf("flags: st%010dend\n", 898);
	// printf("flags: st%+010dend\n", 898);
	// printf("flags: st%0+dend\n", 898);
	// printf("flags: st%-+dend\n", 898);
	// printf("flags: st%-20dend\n", 898);
	// printf("flags: st%20dend\n\n", 898);


	// printf("flags: st% .0dend\n", -898);
	// printf("flags: st%.0dend\n", -898);
	// printf("flags: st%-10dend\n", -898);
	// printf("flags: st% .0dend\n", -898);
	// printf("flags: st%010dend\n", -898);
	// printf("flags: st%+.0dend\n", -898);
	// printf("flags: st%010dend\n", -898);
	// printf("flags: st%+010dend\n", -898);
	// printf("flags: st%0+dend\n", -898);
	// printf("flags: st%-+dend\n", -898);
	// printf("flags: st%-20dend\n", -898);
	// printf("flags: st%20dend\n", -898);

	// printf("flags d: st%+dend\n", 5);
	// printf("flags i: st%+iend\n", 5);
	// printf("flags u: st%+uend\n", 5);
	// printf("flags s: st%+send\n", "str");
	// printf("flags c: st%+cend\n", 'c');
	// printf("flags x: st%+xend\n", 0x5f);
	// printf("flags X: st%+Xend\n", 0X5f);
	// printf("flags p: st%+pend\n", &"ptr");

	
    return (0);
}

// "%#- d%d%d"
// "#-dlafkjd"

//? space and + works with types d, i only
//?space adds and additional one space before the positive number(kinda the space for plus, but probably only one space and only for positive)??
//? a few same flags will react as one flag (this will give only one space: %   d, and this will give no effect: %---d, kinda left identation but no other added spaces or other formatters)
//! " " is ignored when "+" is present
//! 0 ignored when "-" is present, (in both cases, if it is before or after 0 placed even if it is %0-5d) it means that 0's can be only placed before the number; not after with this flag

//? 0 by itself will not have an effect meaning that you want to add 0 0 times before the number, 
//? so it will be kinda ignored for the type when it can be present


//? "." works for s as an amount of bytes to be written (exacty from the format argument!), if just . - it is zero, if .2 - two bytes/letters
//? " ", #, + doesn't work with s. 
//? 0 results undefined behaviour with s.
//? Means that only "-" works for s
//* Empty string as an argument: will print 0 len of (chars for empty string formatter) and all other string of the first arg in printf
//* Empty char as an argument: won't print empty char constant and give an error with not executing the function at all!

//? # doesn't work with d
//? . just will not have an effect on d
//? + will work with 0 only when + is before, look like this: %+010d