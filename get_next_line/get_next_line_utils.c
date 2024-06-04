/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:25:45 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/04 21:20:28 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lst_append(t_list **lst, char *str)
{
	t_list	*new_lst;
	t_list	*tmp;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
	{
		free(str);
		return ;
	}
	new_lst->str = str;
	new_lst->next = NULL;
	if (!(*lst))
		*lst = new_lst;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_lst;
	}
}

int	ft_line_size(t_list *lst)
{
	int		len;
	t_list	*tmp;
	char	*tmp2;

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

void	ft_delone(t_list *lst)
{
	free(lst->str);
	free(lst);
}

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
}
