/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:13:22 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/05 10:20:56 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

static double	ft_power(double base, int power, double output)
{
	if (power < 0)
		return (0.0);
	if (!power)
		return (output);
	else
		return (ft_power(base, power - 1, output * base));
}

static void	ft_handler(double *num, int i, const char *nptr)
{
	int	j;

	j = 1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		*num = *num + (nptr[i] - 48) * ft_power(0.1, j++, 1);
		i++;
	}
}

double	ft_atof(const char *nptr)
{
	int		i;
	double	sign;
	double	num;

	i = 0;
	sign = 1.0;
	num = 0.0;
	while (ft_isblank(nptr[i]) == 1)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = ((num * 10) + (nptr[i] - 48));
		i++;
	}
	if (nptr[i] == '.')
		ft_handler(&num, ++i, nptr);
	return ((num * sign));
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(int ac, char *av[])
{
	if (ac != 2)
		return (0);
	printf("real atof :%f\n", atof(av[1]));
	printf("test atof :%f\n", ft_atof(av[1]));
	return (0);
}*/
