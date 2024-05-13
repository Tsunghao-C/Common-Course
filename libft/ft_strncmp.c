/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:44:29 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/09 12:39:22 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < (n - 1)) && (s1[i] || s2[i]) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
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
	return (0);
}*/
