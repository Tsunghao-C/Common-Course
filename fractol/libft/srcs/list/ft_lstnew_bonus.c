/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:28:30 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/16 16:18:48 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}
/*
#include <stdio.h>
int	main(void)
{
	int	a = 7;
	t_list	*lst;

	lst = ft_lstnew(&a);
	printf("val_lst: %d, add_lst: %p\n", *((int *)(lst->content)), lst->content);
	printf("val_a  : %d, add_a  : %p\n", a, &a);
	printf("add of nex in lst: %p\n", lst->next);
	free(lst);
	return (0);
}*/
