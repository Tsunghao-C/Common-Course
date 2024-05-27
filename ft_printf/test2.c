/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:40:16 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/27 19:43:47 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	//int	*ptr;
	//int	a = 3;
	char	*ptr;
	//char	c;

	//c = 'Q';
	ptr = NULL;
	//ptr = "THIS IS A String!";
	/* //flag tests on c 
	printf("R %d\n", printf("%-2c\n", c));
	printf("T %d\n", ft_printf("%-2c\n", c));
	printf("R %d\n", printf("%12c\n", c));
	printf("T %d\n", ft_printf("%12c\n", c));
	printf("R %d\n", printf("%-c\n", c));
	printf("T %d\n", ft_printf("%-c\n", c));*/
	/* // flag tests on s
	printf ("R %d\n",printf("%-3s\n", ptr));
	printf ("T %d\n",ft_printf("%-3s\n", ptr));
	printf ("R %d\n",printf("%-30s\n", ptr));
	printf ("T %d\n",ft_printf("%-30s\n", ptr));
	printf ("R %d\n",printf("%30s\n", ptr));
	printf ("T %d\n",ft_printf("%30s\n", ptr));
	printf ("R %d\n",printf("%30.10s\n", ptr));
	printf ("T %d\n",ft_printf("%30.10s\n", ptr));
	printf ("R %d\n",printf("%-30.10s\n", ptr));
	printf ("T %d\n",ft_printf("%-30.10s\n", ptr));
	printf ("R %d\n",printf("%10.30s\n", ptr));
	printf ("T %d\n",ft_printf("%10.30s\n", ptr));
	printf ("R %d\n",printf("%10.0s\n", ptr));
	printf ("T %d\n",ft_printf("%10.0s\n", ptr));
	printf ("R %d\n",printf("%10s\n", ptr));
	printf ("T %d\n",ft_printf("%10s\n", ptr));*/
	/* // flag tests on p
	printf ("R %d\n",printf("%-3p\n", ptr));
	printf ("T %d\n",ft_printf("%-3p\n", ptr));
	printf ("R %d\n",printf("%-30p\n", ptr));
	printf ("T %d\n",ft_printf("%-30p\n", ptr));
	printf ("R %d\n",printf("%30p\n", ptr));
	printf ("T %d\n",ft_printf("%30p\n", ptr));
	printf ("R %d\n",printf("%10p\n", ptr));
	printf ("T %d\n",ft_printf("%10p\n", ptr));
	printf ("R %d\n",printf("%p\n", ptr));
	printf ("T %d\n",ft_printf("%p\n", ptr));
	printf ("R %d\n",printf("%-p\n", ptr));
	printf ("T %d\n",ft_printf("%-p\n", ptr));*/
	/* //flag tests on % 
	printf("R %d\n", printf("%-12%\n"));
	printf("T %d\n", ft_printf("%-12%\n"));
	printf("R %d\n", printf("%-012%\n"));
	printf("T %d\n", ft_printf("%-012%\n"));
	printf("R %d\n", printf("%2%\n"));
	printf("T %d\n", ft_printf("%2%\n"));
	printf("R %d\n", printf("%012%\n"));
	printf("T %d\n", ft_printf("%012%\n"));
	printf("R %d\n", printf("%12%\n"));
	printf("T %d\n", ft_printf("%12%\n"));*/
	 // flag test on u
	/*printf("R %u\n", 42);
	ft_printf("T %u\n", 42);
	printf("R %5u\n", 42);
	ft_printf("T %5u\n", 42);
	printf("R %-5u\n", 42);
	ft_printf("T %-5u\n", 42);
	printf("R %5.10u\n", 42);
	ft_printf("T %5.10u\n", 42);
	printf("R %-5.10u\n", 42);
	ft_printf("T %-5.10u\n", 42);
	printf("R %10.5u\n", 42);
	ft_printf("T %10.5u\n", 42);
	printf("R %-10.5u\n", 42);
	ft_printf("T %-10.5u\n", 42);
	printf("R %05.10u\n", 42);
	ft_printf("T %05.10u\n", 42);*/
	//printf("R %-05.10u\n", 42);
	printf("R %010.5u\n", 42);
	ft_printf("T %010.5u\n", 42);
	printf("R %010u\n", 42);
	ft_printf("T %010u\n", 42);
	//printf("R %-010.5u\n", 42);
	return (0);
}
