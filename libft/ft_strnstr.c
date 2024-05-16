/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:39:41 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/16 15:29:35 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	n_len;

	i = 0;
	n_len = 0;
	if (*little == 0)
		return ((char *)big);
	while (little[n_len])
		n_len++;
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
#include <bsd/string.h>
#include <stdio.h>

int	main(int ac, char *av[])
{
	if (ac != 4)
		return (0);
	printf("Str test: %s\n", ft_strnstr(av[1], av[2], atoi(av[3])));
	printf("Str real: %s\n", strnstr(av[1], av[2], atoi(av[3])));
	return (0);
}*/
