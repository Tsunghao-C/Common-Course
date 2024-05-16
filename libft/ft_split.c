/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:13:36 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/16 15:21:46 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_subset(char const *s, char c)
{
	int		i;
	int		count;
	int		anchor;

	i = -1;
	count = 0;
	anchor = -1;
	while (s[++i])
	{
		if (s[i] == c)
		{
			if (i - anchor > 1)
				count++;
			anchor = i;
		}
	}
	if (i - anchor > 1)
		count++;
	return (count);
}

static char	*ft_strchop(char const *s, int start, int end)
{
	char	*str;
	int		i;

	str = (char *)malloc((end - start) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < (end - start - 1))
	{
		str[i] = s[start + i + 1];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		anchor;

	i = -1;
	arr = (char **)malloc((ft_count_subset(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	j = 0;
	anchor = -1;
	while (s[++i])
	{
		if (s[i] == c)
		{
			if (i - anchor > 1)
				arr[j++] = ft_strchop(s, anchor, i);
			anchor = i;
		}
	}
	if (i - anchor > 1)
		arr[j++] = ft_strchop(s, anchor, i);
	arr[j] = 0;
	return (arr);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int ac, char *av[])
{
	if (ac != 3 || (strlen(av[2]) != 1))
		return (0);
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = ft_split(av[1], *(av[2]));
	if (!arr)
		return (0);
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	while (j < i)
		free(arr[j++]);
	free(arr);
	return (0);
}*/
