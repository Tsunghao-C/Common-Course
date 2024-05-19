/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:59:04 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/19 13:18:39 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int	count;

	va_start(ap, fmt);	/* initialize ap (argument pointer) */
	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			count += ft_print_spec(*(++fmt), &ap);
		else
			count += ft_print_char(*fmt);
		++fmt;
	}
	va_end(ap);
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	int	test;
	int	real;
	char	a = 'G';
	
	printf(" ==> Real function <==\n");
	real = printf("Try to print string with backlash %%\\ \" \a \b \e \f \n \r \t \v oct\060 hex\x5a uni\u2B50");
	printf("\n ==> My function <==\n");
	test = ft_printf("Try to print string with backlash %%\\ \" \a \b \e \f \n \r \t \v oct\060 hex\x5a uni\u2B50");
	printf("\n");
	printf("test: %d, real: %d\n", test, real);
	printf(" ==> Real function 2 <== \n");
	real = printf("Specifier c1: %c, %%, c2: %c, s: %s, p: %p\n", a, 'H', "STR", &a);
	printf(" ==> My function 2 <== \n");
	test = ft_printf("Specifier c1: %c, %%, c2: %c, s: %s, p: %p\n", a, 'H', "STR", &a);
	printf("test: %d, real: %d\n", test, real);
	printf(" ==> Real function 3 <== \n");
	real = printf("Spec d: %d, i: %i, u: %u, x: %x, X: %X\n", -42, -42, -42, -42, -42);
	printf(" ==> My function 3 <== \n");
	test = ft_printf("Spec d: %d, i: %i, u: %u, x: %x, X: %X\n", -42, -42, -42, -42, -42);
	printf("test: %d, real: %d\n", test, real);
	return (0);
}*/
