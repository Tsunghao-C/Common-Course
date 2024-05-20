/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:51:13 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/20 14:49:43 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_mem(void *addr)
{
	int				count;
	int				i;
	unsigned long	ad;
	char			temp[(AD_SIZE + 1)];

	i = 0;
	ad = (unsigned long)addr;
	count = 0;
	while (ad > 0)
	{
		temp[i] = HEX_TAB[ad % HEX_SIZE];
		ad /= HEX_SIZE;
		i++;
	}
	temp[i] = '\0';
	count += write(STDOUT_FILENO, "0x", 2);
	while (--i >= 0)
		count += write(STDOUT_FILENO, &temp[i], 1);
	return (count);
}
/*
#include <unistd.h>
#include <stdio.h>
int	main(void)
{
	int	i = 3;

	ft_putmem_fd(&i, STDOUT_FILENO);
	printf("\n%p\n", &i);
	return (0);
}*/
