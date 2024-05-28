/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_wid_pre_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:38:12 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/28 18:14:53 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_with_pre(char *s)
{
	while (*s)
	{
		if (*s == '.')
			return (1);
		s++;
	}
	return (0);
}

static int	ft_arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static void	ft_assign_wid_pre(char *cpy, char **arr, char **wid_pre)
{
	if (ft_arr_size(arr) == 0)
	{
		if (ft_with_pre(cpy) == 1)
			wid_pre[1] = ft_strdup("0");
		return ;
	}
	else if (ft_arr_size(arr) == 1)
	{
		if (ft_with_pre(cpy) == 0)
			wid_pre[0] = ft_strdup(arr[0]);
		else if (*cpy == '.')
			wid_pre[1] = ft_strdup(arr[0]);
		else
		{
			wid_pre[0] = ft_strdup(arr[0]);
			wid_pre[1] = ft_strdup("0");
		}
	}
	else
	{
		wid_pre[0] = ft_strdup(arr[0]);
		wid_pre[1] = ft_strdup(arr[1]);
	}
}

static void	ft_free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_gen_wid_pre(const char *fmt, size_t len, char **wid_pre)
{
	char	*cpy;
	char	**arr;

	cpy = (char *)malloc((len + 1) * sizeof(char));
	if (!cpy)
		return ;
	ft_strlcpy(cpy, fmt, (len + 1));
	arr = ft_split(cpy, '.');
	if (!arr)
	{
		free(cpy);
		return ;
	}
	ft_assign_wid_pre(cpy, arr, wid_pre);
	ft_free_all(arr);
	free(cpy);
}
/* Note
 * If there is a '.' flag, the precision will always be not null
 */
