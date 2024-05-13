/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:54:24 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/13 21:55:02 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = 0;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;
	t_list	*tmp2;

	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (0);
	tmp = lst->next;
	while (tmp)
	{
		ft_lstadd_back(&new_lst, ft_lstnew(f(tmp->content)));
		tmp = tmp->next;
	}
	return (new_lst);
}

#include <stdio.h>
void	*triple_data(void *data)
{
	void	*new;

	new = malloc(sizeof(int));
	if (!new)
		return (0);
	*(int)new = (int)data * 3;
	return (new);
}


