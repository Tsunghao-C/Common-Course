/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:33:37 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/16 15:28:16 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
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
