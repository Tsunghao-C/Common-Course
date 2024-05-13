/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:49:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/08 14:05:43 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
		return (1);
	return (0);
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

int	main(int ac, char *av[])
{
	if ((ac != 2) || (ft_strlen(av[1]) != 1))
	{
		write(1, "Input Error\n", 12);
		return (0);
	}
	int	output;

	output = ft_isalnum(*(av[1]));
	if (output == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	if (isalnum(*(av[1])) == 1)
		write(1, "\n1", 2);
	else
		write(1, "\n0", 2);
	return (0);
}*/
