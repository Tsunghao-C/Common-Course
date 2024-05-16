/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:02:22 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/16 15:44:01 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	*sub = 0;
	if (start >= ft_strlen(s))
		return (sub);
	while (i < len && s[i + start])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>

int	main(int ac, char *av[])
{
	char	*substr;

	if (ac != 4)
		return (0);
	substr = ft_substr(av[1], atoi(av[2]), atoi(av[3]));
	printf("substr is: %s\n", substr);
	free(substr);
	return (0);
}*/
