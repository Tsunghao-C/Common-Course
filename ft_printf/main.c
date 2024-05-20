/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:12:24 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/20 15:37:09 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
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
	real = printf("d:%d, i:%i, u:%u, x:%x, X:%X\n", -42, -42, -42, 42, -42);
	printf(" ==> My function 3 <== \n");
	test = ft_printf("d:%d, i:%i, u:%u, x:%x, X:%X\n", -42, -42, -42, 42, -42);
	printf("test: %d, real: %d\n", test, real);
	printf(" =========>  BONUS PART  <==========\n");
	printf(" ==> Real function 3 <== \n");
	real = printf("d:%06d, x:%06x\n", -42, 42);
	printf(" ==> My function 3 <== \n");
	test = ft_printf("d:%4d, x:%4x\n", -42, 42);
	printf("test: %d, real: %d\n", test, real);
	return (0);
}
