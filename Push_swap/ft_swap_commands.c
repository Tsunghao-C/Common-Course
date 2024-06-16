/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:43:28 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/16 19:11:15 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	tmp->prev = (*lst);
	(*lst)->next = tmp;
	(*lst)->prev = NULL;
}

void	ft_sa(t_list **stk_a)
{
	if (!(*stk_a) || !((*stk_a)->next))
		return ;
	ft_swap(stk_a);
	write(STDOUT_FILENO, "sa\n", 3);
}

void	ft_sb(t_list **stk_b)
{
	if (!(*stk_b) || !((*stk_b)->next))
		return ;
	ft_swap(stk_b);
	write(STDOUT_FILENO, "sb\n", 3);
}

void	ft_ss(t_list **stk_a, t_list **stk_b)
{
	if (!(*stk_a) || !((*stk_a)->next))
		return ;
	if (!(*stk_b) || !((*stk_b)->next))
		return ;
	ft_swap(stk_a);
	ft_swap(stk_b);
	write(STDOUT_FILENO, "ss\n", 3);
}
