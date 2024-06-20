/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:39:41 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/23 14:51:21 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;

	if (!(*little))
		return ((char *)big);
	if (len == 0)
		return (0);
	i = 0;
	n_len = ft_strlen(little);
	while (big[i] && (i < len))
	{
		j = 0;
		while ((j < n_len) && (big[i + j] == little[j]) && (i + j < len))
			j++;
		if (j == n_len)
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%s\n", strnstr(NULL, "fake", 0));
	printf("%s\n", ft_strnstr(NULL, "fake", 0));
	return (0);
}*/
/*
#include <bsd/string.h>
int	main(int ac, char *av[])
{
	if (ac != 4)
		return (0);
	printf("Str test: %s\n", ft_strnstr(av[1], av[2], atoi(av[3])));
	printf("Str real: %s\n", strnstr(av[1], av[2], atoi(av[3])));
	return (0);
}*/
