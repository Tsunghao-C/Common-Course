/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:42:49 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/16 10:58:56 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
/*
#include <stdio.h>
void    ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);

int	main(void)
{
	t_list	*lst;
	int	a = 3;
	int	i = 0;
	t_list	*tmp1;

	lst = ft_lstnew(&a);
	while (i < 10)
	{
		ft_lstadd_front(&lst, ft_lstnew(&a));
		i++;
	}
	printf("size of list is: %d\n", ft_lstsize(lst));
	while (lst)
	{
		tmp1 = lst;
		lst = lst->next;
		free(tmp1);
	}
	return (0);
}*/
