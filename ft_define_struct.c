/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:23:43 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/15 17:26:24 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// char	*ft_strdup(const char *s1)
// {
// 	char	*buffer;
// 	int		i;

// 	buffer = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
// 	if (!buffer)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		buffer[i] = s1[i];
// 		i++;
// 	}
// 	buffer[i] = '\0';
// 	return (buffer);
// }

t_printf	*ft_define_struct(const char *s)
{
	t_printf	*data;
	t_flags		*flags;
	char		*str;

	str = ft_strdup(s);
	data = malloc(sizeof(t_printf));
	if (!data || !str)
		return (NULL);
	data->curr_s = str;
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
