/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:39:29 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/16 16:21:05 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst)
		(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}
/* Note
 * 1. if new is NULL, it won't do anything
 * 2. if lst (or bgn_lst) is NULL, it will be replaced with new
 */
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
	ft_lstadd_front(&lst_1, lst_0);
	tmp1 = lst_1;
	printf("Next content of lst_0 is: %d\n", *(int *)(tmp1->next->content));
	tmp2 = lst_1->next;
	free(tmp2);
	free(lst_1);
	return (0);
}*/
