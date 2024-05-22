/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:13:36 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/22 17:01:17 by tsuchen          ###   ########.fr       */
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

static void	ft_free_all(char **arr, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(arr[i++]);
	free(arr);
}

int	ft_assign_arr(char **arr, char const *s, char c)
{
	int	i;
	int	j;
	int	anchor;

	i = -1;
	j = 0;
	anchor = i;
	while (++i <= (int)ft_strlen(s))
	{
		if (s[i] == c || !s[i])
		{
			if (i - anchor > 1)
			{
				arr[j] = ft_strchop(s, anchor, i);
				if (!arr[j++])
				{
					ft_free_all(arr, j - 1);
					return (0);
				}
			}
			anchor = i;
		}
	}
	arr[j] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = (char **)malloc((ft_count_subset(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	if (ft_assign_arr(arr, s, c) == 0)
		return (0);
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

	i = 0;
	arr = ft_split(av[1], *(av[2]));
	if (!arr)
		return (0);
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	ft_free_all(arr, i);
	return (0);
}*/
