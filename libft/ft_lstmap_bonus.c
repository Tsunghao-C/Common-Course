/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:54:24 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/24 12:10:22 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp_lst;
	void	*tmp_data;

	new_lst = NULL;
	while (lst)
	{
		tmp_data = f(lst->content);
		tmp_lst = ft_lstnew(tmp_data);
		if (!tmp_lst)
		{
			del(tmp_data);
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, tmp_lst);
		lst = lst->next;
	}
	return (new_lst);
}
/* Note
 * 1. if lst is NULL, it will return NULL
 * 2. if malloc fail, it will return NULL
 * 3. if either function "f" or "del" is NULL, it will crash
 */
/*
#include <stdio.h>
void	*triple_data(void *data)
{
	void	*new;

	new = malloc(sizeof(int));
	if (!new)
		return (0);
	*(int *)new = *(int *)data * 3;
	return (new);
}

void	del_content(void *content)
{
	free(content);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}

void	print_out(void *content)
{
	printf("%d\n", *(int *)content);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		del(tmp->content);
		free(tmp);
	}
}

int	main(void)
{
	int	a = 3;
	int	b = 4;
	int	i = 0;
	t_list	*org;
	t_list	*new;
	t_list	*tmp1;

	org = ft_lstnew(&a);
	while (i++ < 9)
		ft_lstadd_back(&org, ft_lstnew(&b));
	printf("original list:\n");
	ft_lstiter(org, &print_out);
	new = ft_lstmap(org, &triple_data, &del_content);
	printf("mapping  list:\n");
	ft_lstiter(new, &print_out);
	tmp1 = org;
	while (org)
	{
		tmp1 = org;
		org = org->next;
		free(tmp1);
	}
	ft_lstclear(&new, &del_content);
	return (0);
}*/
