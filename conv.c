/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vponthus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:16:03 by vponthus          #+#    #+#             */
/*   Updated: 2026/10/28 17:09:37 by vponthus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
//#include "ft_printf.h"

//int	ft_printf_c(char c)
//{
//	write(1, &c, 1);
//	return (1);
//}
//
//int	ft_printf_s(char *s)
//{
//	int	i;
//
//	i = 0;
//	while (s[i])
//	{
//		write(1, &s[i], 1);
//		i++;
//	}
//	return(i);
//}

int	ft_printf_p(char *p)
{
	unsigned long	adr;
	char		*base;
	char		str[16];
	int		i;
	int		j;

	j = 0;
	adr = (unsigned long)p;
	base = "0123456789abcdef";
	while (adr > 0)
	{
		i = adr % 16;
		str[j] = base[i];
		adr /= 16;
		j++;
	}
	write(1, "0x", 2);
	i = j;
	while (i > 0)
	{
		write (1, &str[i], 1);
		i--;
	}
	return (j + 2);
}

int	main(void)
{
	char	*p;
	char	test[] = "dwdwd";

	p = test;
	ft_printf_p(p);
	return (0);
}
