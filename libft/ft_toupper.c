/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:52:19 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/08 19:22:20 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
/*
#include <unistd.h>
#include <ctype.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char *av[])
{
	if ((ac != 2) || (ft_strlen(av[1]) != 1))
	{
		write (1, "Input Error\n", 12);
		return (0);
	}
	ft_putchar(ft_toupper(*(av[1])));
	write(1, "\n", 1);
	ft_putchar(toupper(*(av[1])));
	write(1, "\n", 1);
	return (0);
}*/
