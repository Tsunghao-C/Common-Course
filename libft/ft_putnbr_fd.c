/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:29:35 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/09 20:38:15 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr_fd((nb / 10), fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}
/*
#include <stdlib.h>
int	main(int ac, char *av[])
{
	if (ac != 2)
		return (0);
	ft_putnbr_fd(atoi(av[1]), 1);
	return (0);
}*/
