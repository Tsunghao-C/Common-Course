/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:55:01 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/09 12:40:38 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	n_len;

	i = 0;
	n_len = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (needle[n_len])
		n_len++;
	while (haystack[i] && (i < len))
	{
		j = 0;
		while ((j < n_len) && (haystack[i + j] == needle[j]))
			j++;
		if (j == n_len)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(int ac, char *av[])
{
	if (ac != 4)
		return (0);
	printf("Str test: %s\n", ft_strnstr(av[1], av[2], atoi(av[3])));
	printf("Str real: %s\n", strnstr(av[1], av[2], atoi(av[3])));
	return (0);
}*/
