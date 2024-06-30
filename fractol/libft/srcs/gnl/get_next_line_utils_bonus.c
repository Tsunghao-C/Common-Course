/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:25:45 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/15 13:58:28 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_lst_append(t_list_gnl **lst, char *str)
{
	t_list_gnl	*new_lst;
	t_list_gnl	*tmp;

	new_lst = (t_list_gnl *)malloc(sizeof(t_list_gnl));
	if (!new_lst)
		return ;
	new_lst->str = str;
	new_lst->next = NULL;
	if (!(*lst))
	{
		*lst = new_lst;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_lst;
}

int	ft_line_size(t_list_gnl *lst)
{
	int			len;
	t_list_gnl	*tmp;
	char		*tmp2;

	len = 0;
	tmp = lst;
	while (tmp)
	{
		tmp2 = tmp->str;
		while (*tmp2)
		{
			if (*tmp2 == '\n')
				return (++len);
			len++;
			tmp2++;
		}
		tmp = tmp->next;
	}
	return (len);
}

void	ft_delone(t_list_gnl *lst)
{
	free(lst->str);
	free(lst);
}
/*
size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	n;
	int		i;

	i = 0;
	n = ft_strlen(s);
	dup = (char *)malloc((n + 1) * sizeof(char));
	if (!dup)
		return (0);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}*/
