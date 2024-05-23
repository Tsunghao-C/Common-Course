/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_wid_pre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:38:12 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/21 19:05:40 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_with_pre(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '.')
			return (1);
	}
	return (0);
}

static void	ft_assign_wid_pre(char *cpy, char **arr, int *wid, int *pre)
{
	if (ft_with_pre(cpy) == 0)
	{
		*wid = ft_atoi(arr[0]);
		*pre = 0;
	}
	else
	{
		if (!arr[1])
		{
			*wid = 0;
			*pre = ft_atoi(arr[0]);
		}
		else
		{
			*wid = ft_atoi(arr[0]);
			*pre = ft_atoi(arr[1]);
		}
	}
}

void	ft_gen_wid_pre(const char *fmt, size_t len, int *wid, int *pre)
{
	char	*cpy;
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cpy = (char *)malloc((len + 1) * sizeof(char));
	if (!cpy)
		return ;
	ft_strlcpy(cpy, fmt, (len + 1));
	arr = ft_split(cpy, '.');
	ft_assign_wid_pre(cpy, arr, wid, pre);
	while (arr[i])
		i++;
	while (j < i)
		free(arr[j++]);
	free(arr);
	free(cpy);
}
