/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:18:13 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/22 17:44:10 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
/*
int	main(void)
{
	int	num = 72;

	printf("-  flag:%-4d\n", num);
	printf("-  flag:%-14.3s\n", "HELLO!!");
	printf("   flag:%14.3s\n", "HELLO!!");
	printf(".  flag:%4.7d\n", num);
	printf(".  flag:%4.3d\n", num);
	printf(".  flag:%-4.3d\n", num);
	printf(" - flag:% -4d\n", num);
	printf("   flag:% 4d\n", num);
	printf("-+ flag:%-+4d\n", num);
	printf("+- flag:%+-4d\n", num);
	printf("+  flag:%+4d\n", num);
	return (0);
}*/

int main()
{
	int num = -444444442;
	//double pi = 3.14159;
	//char str[] = "Hello, World!";
	// Combinations
	printf("Real function int \n");
	fflush(stdout);

	printf("%d\n", num);         // Left-justify within width 10
	printf("%-5d\n", num);         // Left-justify within width 10
	printf("%10d\n", num);         // space-pad within width 10
	printf("%010d\n", num);         // Zero-pad within width 10
	printf("%.5d\n", num);          // Precision of 5 for integer
	printf("%-.10d\n", num);        // Left-justify overrides zero-padding
	printf("%10.5d\n", num);       // Precision 5 overrides zero-padding
	printf("%5.10d\n", num);       // Precision 5 overrides zero-padding
	printf("%-10.5d\n", num);      // Left-justify with precision 5
	printf("\n Test function int \n");
	fflush(stdout);

	ft_printf("%d\n", num);         // Left-justify within width 10
	ft_printf("%-5d\n", num);         // space-pad within width 10
	ft_printf("%10d\n", num);         // space-pad within width 10
	ft_printf("%010d\n", num);         // Zero-pad within width 10
	ft_printf("%.5d\n", num);          // Precision of 5 for integer
	ft_printf("%-.10d\n", num);        // Left-justify overrides zero-padding
	ft_printf("%10.5d\n", num);       // Precision 5 overrides zero-padding
	ft_printf("%5.10d\n", num);       // Precision 5 overrides zero-padding
	ft_printf("%-10.5d\n", num);      // Left-justify with precison 5
/*	
	printf("\n hex \n");
	printf("%-10x\n", num);         // Left-justify within width 10
	printf("%10x\n", num);         // space-pad within width 10
	printf("%010x\n", num);         // Zero-pad within width 10
	printf("%.5x\n", num);          // Precision of 5 for integer
	printf("%-.10x\n", num);        // Left-justify overrides zero-padding
	printf("%10.5x\n", num);       // Precision 5 overrides zero-padding
	printf("%-10.5x\n", num);      // Left-justify with precision 5
				       //
	printf("\n float \n");
	printf("%-10.2f\n", pi);        // Left-justify with precision 2
	printf("%010.2f\n", pi);        // Zero-pad with precision 2
	printf("%-10.2f\n", pi);       // Left-justify with precision 2

	printf("\n str \n");
	printf("%-10.5s\n", str);       // Left-justify with precision 5
	printf("%10.5s\n", str);       // Zero-pad with precision 5 (unusual case)
	printf("%-10.5s\n", str);      // Left-justify with precision 5
	*/
	return 0;
}

