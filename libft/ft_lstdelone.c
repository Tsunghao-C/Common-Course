/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:09:48 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/10 13:52:13 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>
t_list	*ft_lstnew(void *content);

void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	int	a = 3;
	t_list	*lst;
	t_list	*cont;

	cont = ft_lstnew(&a);
	lst = ft_lstnew(cont);
	printf("Before DEL, add of lst: %p | lst_cont: %p | cont: %p | cont_cont: %p\n", lst, lst->content, cont, cont->content);
	ft_lstdelone(lst, &del_content);
	printf("After  DEL, add of lst: %p | lst_cont: %p | cont: %p | cont_cont: %p\n", lst, lst->content, cont, cont->content);
	return (0);
}*/
