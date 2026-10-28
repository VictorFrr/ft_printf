/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vponthus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:49:23 by vponthus          #+#    #+#             */
/*   Updated: 2026/10/28 15:55:04 by vponthus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int ft_printf(const char *conv, ...)
{
	int	i;
	va_list args;
	
	va_start(args, conv);
	i = 0;
	if (conv == NULL)
		return (0);
	while (conv[i])
	{
		if (conv[i] == '%')
		{
			i++;
			if (conv[i] == 'c')
				return (ft_printf_c(va_arg(args, int)));
			if (conv[i] == 's')
				return (ft_printf_s(va_arg(args, char *)));
			if (conv[i] == 'p')
				return (ft_printf_s(va_arg(args, char *)));
			if (conv[i] == 'd')
				return (ft_printf_s(va_arg(args, char *)));
			if (conv[i] == 'i')
				return (ft_printf_s(va_arg(args, char *)));
			if (conv[i] == 'u')
				return (ft_printf_s(va_arg(args, char *)));
			if (conv[i] == 'x')
				return (ft_printf_s(va_arg(args, char *)));
			if (conv[i] == 'X')
				return (ft_printf_s(va_arg(args, char *)));
			if (conv[i] == '%')
				return (ft_printf_s(va_arg(args, char *)));
		}
		write(1, &conv[i], 1);
		i++;
	}
	va_end(args);
}
