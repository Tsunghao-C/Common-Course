/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:43:28 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/20 02:00:44 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_swap(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	tmp->prev = (*lst);
	if ((*lst)->next)
		(*lst)->next->prev = tmp;
	(*lst)->next = tmp;
	(*lst)->prev = NULL;
}

void	ft_sa(t_list **stk_a, t_list **stk_b)
{
	while (*stk_b)
		break ;
	if (!(*stk_a) || !((*stk_a)->next))
		return ;
	ft_swap(stk_a);
}

void	ft_sb(t_list **stk_a, t_list **stk_b)
{
	while (*stk_a)
		break ;
	if (!(*stk_b) || !((*stk_b)->next))
		return ;
	ft_swap(stk_b);
}

void	ft_ss(t_list **stk_a, t_list **stk_b)
{
	if (!(*stk_a) || !((*stk_a)->next))
		return ;
	if (!(*stk_b) || !((*stk_b)->next))
		return ;
	ft_swap(stk_a);
	ft_swap(stk_b);
}
