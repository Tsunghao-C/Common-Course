/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:27:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/15 11:27:37 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && (((unsigned char *)s1)[i]
		== ((unsigned char *)s2)[i]))
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int ac, char *av[])
{
	if (ac != 4)
	{
		printf("Input Error\n");
		return (0);
	}
	int	test;
	int	real;

	test = ft_memcmp(av[1], av[2], atoi(av[3]));
	real = memcmp(av[1], av[2], atoi(av[3]));
	printf("test cmp: %d\n", test);
	printf("real cmp: %d\n", real);
	return (0);
}*/
