/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:39:29 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/10 13:09:21 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
/*
#include <stdio.h>
t_list *ft_lstnew(void	*content);
int	main(void)
{
	int	a = 4;
	int	b = 3;
	t_list	*tmp1;
	t_list	*tmp2;

	t_list	*lst_0;
	t_list	*lst_1;
	lst_0 = ft_lstnew(&a);
	lst_1 = ft_lstnew(&b);
	ft_lstadd_back(&lst_1, lst_0);
	tmp1 = lst_1;
	printf("Next content of lst_1 is: %d\n", *(int *)(tmp1->next->content));
	tmp2 = lst_1->next;
	free(tmp2);
	free(lst_1);
	return (0);
}*/
