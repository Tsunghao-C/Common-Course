/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:59:04 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/30 18:44:12 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (ft_is_spec(*(fmt + 1)) == 1)
				count += ft_print_spec(*(++fmt), &ap);
			else
				fmt = ft_procs_flag(++fmt, &ap, &count);
		}
		else
			count += ft_print_char(*fmt);
		if (!fmt)
			return (va_end(ap), -1);
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
	real = printf("No arg %%\\\"\a\b\e\f\n\r\t\voct\060hex\x5auni\u2B50");
	printf("\n ==> My function <==\n");
	test = ft_printf("No arg %%\\\"\a\b\e\f\n\r\t\voct\060hex\x5auni\u2B50");
	printf("\n");
	printf("test: %d, real: %d\n", test, real);
	printf(" ==> Real function 2 <== \n");
	real = printf("Spec c1:%c, %%, c2:%c, s:%s, p:%p\n", a, 'H', "STR", &a);
	printf(" ==> My function 2 <== \n");
	test = ft_printf("Spec c1:%c, %%, c2:%c, s:%s, p:%p\n", a, 'H', "STR", &a);
	printf("test: %d, real: %d\n", test, real);
	printf(" ==> Real function 3 <== \n");
	real = printf("d:%d, i:%i, u:%u, x:%x, X:%X\n", -42, -42, -42, -42, -42);
	printf(" ==> My function 3 <== \n");
	test = ft_printf("d:%d, i:%i, u:%u, x:%x, X:%X\n", -42, -42, -42, -42, -42);
	printf("test: %d, real: %d\n", test, real);
	return (0);
}*/
