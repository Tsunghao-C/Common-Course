/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:49:53 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/16 14:39:08 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
		return (1);
	return (0);
}
/*
#include <stdio.h>
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
		printf("Input Error\n");
		return (0);
	}
	int	test;
	int	real;

	test = ft_isalnum(*(av[1]));
	real = isalnum(*(av[1]));
	if (test == 0)
		printf("test = %d,  not alnum\n", test);
	else 
		printf("test = %d, is alnum\n", test);
	if (real == 0)
		printf("real = %d,  not alnum\n", real);
	else 
		printf("real = %d, is alnum\n", real);
	return (0);
}*/
