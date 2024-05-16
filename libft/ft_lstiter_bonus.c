/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:40:23 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/16 12:04:39 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
#include <stdio.h>
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);

void	print_out(void *content)
{
	printf("%d\n", *(int *)content + 1);
}

int	main(void)
{
	int	a = 3;
	int	i = 0;
	t_list	*lst;
	t_list	*tmp;

	lst = ft_lstnew(&a);
	while (i < 9)
	{
		ft_lstadd_back(&lst, ft_lstnew(&i));
		i++;
	}
	ft_lstiter(lst, &print_out);
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (0);
}*/
