/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:26:43 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/09 10:59:08 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isblank(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isblank(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = ((num * 10) + (str[i] - 48));
		i++;
	}
	return ((num * sign));
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char *av[])
{
	if (ac != 2)
		return (0);
	printf("ft_atoi is: %d\n", ft_atoi(av[1]));
	printf("atoi is   : %d\n", atoi(av[1]));
	return (0);
}*/
