/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:10:58 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/09 20:41:02 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char const *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <string.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	long	nb;

	nb = (long)nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr((nb / 10));
	ft_putchar((nb % 10) + '0');
}

int	main(int ac, char *av[])
{
	if (ac != 2)
		return (0);
	ft_putnbr(ft_strlen(av[1]));
	write(1, "\n", 1);
	ft_putnbr(strlen(av[1]));
	write(1, "\n", 1);
	return (0);
}*/
