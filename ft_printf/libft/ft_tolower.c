/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:17:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/16 15:40:09 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
/*
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
	ft_putchar(ft_tolower(*(av[1])));
	write(1, "\n", 1);
	ft_putchar(tolower(*(av[1])));
	write(1, "\n", 1);
	return (0);
}*/
