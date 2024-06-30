/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:13:36 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/28 13:48:46 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strchop(char **arr, char *start, char *end, int index)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
		return (0);
	}
	ft_strlcpy(str, start, end - start + 1);
	arr[index] = str;
	return (1);
}

static char	*ft_find_next_quote(char **arr, char *s, int *index)
{
	char	*next_quote;

	next_quote = ft_strchr(s + 1, '\'');
	if (next_quote - s > 1)
	{
		if (!ft_strchop(arr, s + 1, next_quote, *index))
			return (NULL);
		*index += 1;
	}
	return (next_quote);
}

static void	ft_assign_arr(char **arr, char *s, char c)
{
	int		j;
	char	*anchor;

	j = 0;
	anchor = s;
	while (*s)
	{
		if (*s == c || *s == '\'')
		{
			if (s - anchor > 0)
				if (!ft_strchop(arr, anchor, s, j++))
					return ;
			if (*s == '\'')
			{
				s = ft_find_next_quote(arr, s, &j);
				if (!s)
					return ;
			}
			anchor = s + 1;
		}
		s++;
	}
	if (s - anchor > 0)
		if (!ft_strchop(arr, anchor, s, j++))
			return ;
}

static int	ft_count_subset(char *s, char c)
{
	int		cnt;
	char	*anchor;

	cnt = 0;
	anchor = s;
	while (*s)
	{
		if (*s == c || *s == '\'')
		{
			if (s - anchor > 0)
				cnt++;
			if (*s == '\'')
			{
				if (ft_strchr(s + 1, '\'') - s > 1)
					cnt++;
				s = ft_strchr(s + 1, '\'');
			}
			anchor = s + 1;
		}
		s++;
	}
	if (s - anchor > 0)
		cnt++;
	return (cnt);
}

char	**ft_split_quote(char const *s, char c)
{
	char	**arr;
	int		n_subset;

	n_subset = ft_count_subset((char *)s, c);
	arr = (char **)malloc((n_subset + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	ft_assign_arr(arr, (char *)s, c);
	if (!arr)
		return (NULL);
	arr[n_subset] = NULL;
	return (arr);
}
/* Note
 * 1. if s is NULL, it will crash
 * 2. if any of malloc fail, it will return NULL
 * 3. if s is empty, it will return an empty arr with a NULL
 */
/*
#include <stdio.h>
#include <string.h>

void	ft_free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	main(int ac, char *av[])
{
	if (ac != 3 || (strlen(av[2]) != 1))
		return (0);
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split_quote(av[1], *(av[2]));
	if (!arr)
		return (0);
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	ft_free_all(arr);
	return (0);
}*/
