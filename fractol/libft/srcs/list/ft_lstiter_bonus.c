/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:40:23 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/24 12:13:18 by tsuchen          ###   ########.fr       */
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
/* Note
 * 1. if lst is NULL, nothing happen
 * 2. if funciton "f" is NULL but lst is not NULL, it will crash
 */
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
