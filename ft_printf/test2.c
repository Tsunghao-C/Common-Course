/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:40:16 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/28 19:46:07 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	//int	*ptr;
	//int	a = 3;
	//char	*ptr;
	//char	c;

	//c = 'Q';
	//ptr = NULL;
	//ptr = "THIS IS A String!";
	// space flag test on d
	printf("R 11 |% d\n", -1);
	ft_printf("T 11 |% d\n", -1);
	printf("R 11 |% 3d\n", -1);
	ft_printf("T 11 |% 3d\n", -1);
	printf("R 11 |% 03d\n", -1);
	ft_printf("T 11 |% 03d\n", -1);
	printf("R 11 |%+d\n", -1);
	ft_printf("T 11 |%+d\n", -1);
	printf("R 11 |%+3d\n", -1);
	ft_printf("T 11 |%+3d\n", -1);
	printf("R 11 |%+03d\n", -1);
	ft_printf("T 11 |%+03d\n", -1);
	// . flag test on s
	/*printf("1 |%.s\n", "");
	ft_printf("1 |%.s\n", "");
	printf("2 |%.1s\n", "");
	ft_printf("2 |%.1s\n", "");
	printf("3 |%.1s\n", "");
	ft_printf("3 |%.1s\n", "");
	printf("4 |%.s\n", "");
	ft_printf("4 |%.s\n", "");
	printf("R 5 |%.s\n", "-");
	ft_printf("T 5 |%.s\n", "-");
	printf("R 5 |%.0s\n", "-");
	ft_printf("T 5 |%.0s\n", "-");
	printf("6 |%.2s %.1s\n", "", "-");
	ft_printf("6 |%.2s %.1s\n", "", "-");
	printf("7 |%.3s %.2s\n", " - ", "");
	ft_printf("7 |%.3s %.2s\n", " - ", "");
	printf("8 |%.1s %.2s %.3s %.4s\n", " - ", "", "4", "");
	ft_printf("8 |%.1s %.2s %.3s %.4s\n", " - ", "", "4", "");
	printf("9 |%.2s %.3s %.4s %.5s %.1s\n", " - ", "", "4", "", "2 ");
	ft_printf("9 |%.2s %.3s %.4s %.5s %.1s\n", " - ", "", "4", "", "2 ");*/
	// # flag tests
	/*printf("1 |%#x\n", 0);
	ft_printf("1 |%#x\n", 0);
	printf("25|%#lx\n", LONG_MIN);
	ft_printf("25|%#x\n", LONG_MIN);
	printf("29|%#x %#x %#lx %#lx %#lx %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("29|%#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);*/
	// - flag tests
	/*printf("31R |%-2d\n", -1);
	ft_printf("31T |%-2d\n", -1);*/
	// 0 flag tests
	/*printf("15 |%04d\n", -14);
	ft_printf("15 |%04d\n", -14);
	printf("16 |%05d\n", -15);
	ft_printf("16 |%05d\n", -15);
	printf("17 |%06d\n", -16);
	ft_printf("17 |%06d\n", -16);
	printf("23 |%011ld\n", LONG_MAX);
	ft_printf("23 |%011d\n", LONG_MAX);
	printf("24 |%012ld\n", LONG_MIN);
	ft_printf("24 |%012d\n", LONG_MIN);
	printf("25 |%013d\n", UINT_MAX);
	ft_printf("25 |%013d\n", UINT_MAX);
	printf("26 |%014lu\n", ULONG_MAX);
	ft_printf("26 |%014d\n", ULONG_MAX);
	printf("27 |%015lld\n", 9223372036854775807LL);
	ft_printf("27 |%015d\n", 9223372036854775807LL);
	printf("28 |%09d %010d %011ld %012ld %013ld %014d %015d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("28 |%09d %010d %011ld %012ld %013ld %014d %015d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);*/
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
	printf ("R %d\n",printf("%-10p\n", ptr));
	printf ("T %d\n",ft_printf("%-10p\n", ptr));
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
	/* // flag test on u
	printf("R %u\n", 42);
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
	ft_printf("T %05.10u\n", 42);
	//printf("R %-05.10u\n", 42);
	printf("R %010.5u\n", 42);
	ft_printf("T %010.5u\n", 42);
	printf("R %010u\n", 42);
	ft_printf("T %010u\n", 42);
	//printf("R %-010.5u\n", 42);*/
	/* // flag test on x and X
	printf("R %x\n", 79);
	ft_printf("T %x\n", 79);
	printf("R %10x\n", 79);
	ft_printf("T %10x\n", 79);
	printf("R %010x\n", 79);
	ft_printf("T %010x\n", 79);
	printf("R %-10x\n", 79);
	ft_printf("T %-10x\n", 79);
	printf("R %10.x\n", 79);	//         4f
	ft_printf("T %10.x\n", 79);	// 000000004f
	printf("R %#10.x\n", 79);	//       0x4f
	ft_printf("T %#10.x\n", 79);	// 0x000000004f
	printf("R %10.1x\n", 79);
	ft_printf("T %10.1x\n", 79);
	printf("R %1.10x\n", 79);
	ft_printf("T %1.10x\n", 79);
	printf("R %-1.10x\n", 79);
	ft_printf("T %-1.10x\n", 79);
	//printf("R %-01.10x\n", 79);
	printf("R %-#10.10x\n", 79);
	ft_printf("T %-#10.10x\n", 79);
	printf("R %#10.10x\n", 79);
	ft_printf("T %#10.10x\n", 79);
	printf("R %#10x\n", 79);
	ft_printf("T %#10x\n", 79);
	printf("R %#-10x\n", 79);
	ft_printf("T %#-10x\n", 79);
	printf("R %#.10x\n", 79);
	ft_printf("T %#.10x\n", 79);*/
	/*// flag test on u and i
	printf("R %d\n", 123);
	ft_printf("T %d\n", 123);
	printf("R % d\n", 123);
	ft_printf("T % d\n", 123);
	printf("R %+d\n", 123);
	ft_printf("T %+d\n", 123);
	printf("R %5d\n", 123);
	ft_printf("T %5d\n", 123);
	printf("R %+5d\n", 123);
	ft_printf("T %+5d\n", 123);
	printf("R % 5d\n", 123);
	ft_printf("T % 5d\n", 123);
	printf("R % 5.10d\n", 123);
	ft_printf("T % 5.10d\n", 123);
	printf("R %+d\n", -123);	//-123
	ft_printf("T %+d\n", -123);	//--123
	printf("R %5d\n", -123);	// -123
	ft_printf("T %5d\n", -123);	// --123
	printf("R %+5d\n", -123);
	ft_printf("T %+5d\n", -123);
	printf("R % 5d\n", -123);
	ft_printf("T % 5d\n", -123);*/
	return (0);
}
