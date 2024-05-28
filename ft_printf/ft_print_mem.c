/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:51:13 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/28 15:56:15 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_mem(void *addr)
{
	int				count;
	int				i;
	unsigned long	ad;
	char			temp[(AD_SIZE + 1)];

	i = 0;
	if (!addr)
		return (write(STDOUT_FILENO, "(nil)", 5));
	ad = (unsigned long)addr;
	count = 0;
	while (ad > 0)
	{
		temp[i++] = HEX_TAB[ad % HEX_SIZE];
		ad /= HEX_SIZE;
	}
	temp[i] = '\0';
	count += write(STDOUT_FILENO, "0x", 2);
	while (--i >= 0)
		count += write(STDOUT_FILENO, &temp[i], 1);
	return (count);
}
/* Note
 * 1. For some system, the output of NULL ptr is 0x0. need to change the 
 * pretection as below:
	//if (!addr)
	//	temp[i++] = '0';
 */
/*
#include <unistd.h>
#include <stdio.h>
int	main(void)
{
	//int	i = 3;
	int	*i;

	i = NULL;
	ft_print_mem(i);
	printf("\n%p\n", i);
	return (0);
}*/
