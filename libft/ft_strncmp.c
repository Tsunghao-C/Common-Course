/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:39:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/23 23:14:27 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < (n - 1)) && (s1[i] || s2[i]) && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int ac, char *av[])
{
	if (ac != 4)
		return (0);
	printf("test: %d\n",ft_strncmp(av[1], av[2], atoi(av[3])));
	printf("real: %d\n", strncmp(av[1], av[2], atoi(av[3])));
	printf("m test1: %d\n", ft_strncmp("testss", "test1", 5));
	printf("m real1: %d\n", strncmp("testss", "test1", 5));
	printf("m test: %d\n", ft_strncmp("test\200", "test\0", 6));
	printf("m real: %d\n", strncmp("test\200", "test\0", 6));
	return (0);
}*/
