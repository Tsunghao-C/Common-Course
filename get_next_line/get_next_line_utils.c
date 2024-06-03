/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:25:45 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/03 19:17:19 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_gen_nl(t_list *lst)
{
	char	*next_line;
	char	*tmp2;
	int		i;

	if (ft_line_size(lst) == 0)
		return (NULL);
	next_line = (char *)malloc((ft_line_size(lst) + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	i = 0;
	while (lst)
	{
		tmp2 = lst->str;
		while (*tmp2 && *tmp2 != '\n')
			next_line[i++] = *tmp2++;
		if (*tmp2 == '\n')
		{
			next_line[i++] = '\n';
			break ;
		}
		lst = lst->next;
	}
	next_line[i] = '\0';
	return (next_line);
}

void	ft_fetch_nl(int fd, t_list **bgn_lst)
{
	int		nu_rd;
	char	*buff;

	while (!ft_have_nl_lst(*bgn_lst))
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return ;
		nu_rd = read(fd, buff, BUFFER_SIZE);
		if (!nu_rd || nu_rd == -1)
		{
			free(buff);
			return ;
		}
		buff[nu_rd] = '\0';
		ft_lst_append(bgn_lst, buff);
	}
}

void	ft_update_list(t_list **lst)
{
	t_list	*tmp;
	char	*str_left;
	char	*tmp2;

	tmp = *lst;
	while ((*lst)->next)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_delone(tmp);
	}
	tmp2 = (*lst)->str;
	while (*tmp2 && *tmp2 != '\n')
		tmp2++;
	if (*tmp2 == '\n')
		tmp2++;
	str_left = (char *)malloc((ft_strlen(tmp2) + 1) * sizeof(char));
	if (!str_left)
		return ;
	ft_strlcpy(str_left, tmp2, ft_strlen(tmp2) + 1);
	ft_delone(*lst);
	*lst = NULL;
	ft_lst_append(lst, str_left);
}
