/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:51:13 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/18 12:32:18 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putmem_fd(void *addr, int fd)
{
	int	i;
	unsigned long	ad;
	char	temp[(AD_SIZE + 1)];

	i = 0;
	ad = (unsigned long)addr;
	temp[0] = '\0';
	while (i < AD_SIZE)
	{
		temp[i] = HEX_TAB[ad % HEX_SIZE];
		ad /= HEX_SIZE;
		i++;
	}
	temp[i] = '\0';
	write(fd, "0x", 2);
	while (--i >= 0)
		write(fd, &temp[i], 1);
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
