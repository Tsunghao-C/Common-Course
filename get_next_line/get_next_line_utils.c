/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:25:45 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/02 20:55:50 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_lst_append(t_list **lst, char *str)
{
	t_list	*new_lst;
	t_list	*tmp;

	new_lst = (t_list *)malloc(sizeof(t_list));
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

int	ft_have_nl_lst(t_list *bgn_lst)
{
	t_list	*tmp;
	char	*tmp2;

	tmp = bgn_lst;
	while (tmp)
	{
		tmp2 = tmp->str;
		while (*tmp2)
		{
			if (*tmp2 == '\n')
				return (1);
			tmp2++;
		}
		tmp = tmp->next;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}

int	ft_line_size(t_list *lst)
{
	int	len;
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

char	*ft_gen_nl(t_list **lst)
{
	char	*next_line;
	t_list	*tmp;
	char	*tmp2;
	int	i;

	next_line = (char *)malloc((ft_line_size(*lst) + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	tmp = *lst;
	i = 0;
	while (tmp)
	{
		tmp2 = tmp->str;
		while (*tmp2)
		{
			if (*tmp2 == '\n')
			{
				next_line[i++] = '\n';
				next_line[i] = '\0';
				return (next_line);
			}
			next_line[i++] = *tmp2++;
		}
		tmp = tmp->next;
	}
	return (next_line);
}

void	ft_fetch_nl(int fd, t_list **bgn_lst)
{
	int	nu_rd;
	char	*buff;

	while (!ft_have_nl_lst(*bgn_lst))
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return ;
		nu_rd = read(fd, buff, BUFFER_SIZE);
		if (!nu_rd)
		{
			free(buff);
			return ;
		}
		buff[nu_rd] = '\0';
		ft_lst_append(bgn_lst, buff);
	}
	/*
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		buff[BUFFER_SIZE] = '\0';
		tmp_str = ft_strdup(buff);
		new_lst = ft_lstnew(tmp_str);
		if (!new_lst)
		{
			free(tmp_str);
			ft_lstclear(bgn_lst);
				return ;
		}
		ft_lstadd_back(bgn_lst, new_lst);
		if (ft_have_nl(buff) == 1)
			break ;
	}*/
}

void	ft_update_list(t_list **lst)
{
	t_list	*tmp;
	char	*str_left;
	int	i;
	char	*tmp2;

	tmp = *lst;
	while ((*lst)->next)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->str);
		free(tmp);
	}
	tmp2 = (*lst)->str;
	while (*tmp2 && *tmp2 != '\n')
		tmp2++;
	i = ft_strlen((*lst)->str) - (tmp2 - (*lst)->str + 1);
	str_left = (char *)malloc((i + 1) * sizeof(char));
	if (!str_left)
		return ;
	i = 0;
	while (*(++tmp2))
		str_left[i++] = *tmp2;
	str_left[i] = '\0';
	free((*lst)->str);
	free(*lst);
	ft_lst_append(lst, str_left);
}
