/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:08:46 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/21 17:15:10 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int	main(void)
{
	int	i;
	int	j;

	i = 0;
	j = -42;
	while (i < 7)
	{
		write(STDOUT_FILENO, "0", 1);
		i++;
	}
	ft_putnbr(j);
	/*
	write(STDOUT_FILENO, "-", 1);
	write(STDOUT_FILENO, "4", 1);
	write(STDOUT_FILENO, "2", 1);
	*/
	return (0);
}
