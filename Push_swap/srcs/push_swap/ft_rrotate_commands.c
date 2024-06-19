/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:20:59 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/19 14:48:06 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rrotate(t_list **lst)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst);
	if (!(tmp->prev))
		return ;
	(tmp->prev)->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_front(lst, tmp);
}

void	ft_rra(t_list **stk_a, int rep)
{
	if (!(*stk_a) || !rep)
		return ;
	ft_rrotate(stk_a);
	write(STDOUT_FILENO, "rra\n", 4);
	ft_rra(stk_a, rep - 1);
}

void	ft_rrb(t_list **stk_b, int rep)
{
	if (!(*stk_b) || !rep)
		return ;
	ft_rrotate(stk_b);
	write(STDOUT_FILENO, "rrb\n", 4);
	ft_rrb(stk_b, rep - 1);
}

void	ft_rrr(t_list **stk_a, t_list **stk_b, int rep)
{
	if (!(*stk_a) || !(*stk_b) || !rep)
		return ;
	ft_rrotate(stk_a);
	ft_rrotate(stk_b);
	write(STDOUT_FILENO, "rrr\n", 4);
	ft_rrr(stk_a, stk_b, rep - 1);
}

void	ft_combo_rrr_rrx(t_list **from, t_list **to, int rep_1, int rep_2)
{
	if (rep_1 > rep_2)
	{
		ft_rrr(from, to, rep_2);
		ft_rra(from, rep_1 - rep_2);
	}
	else
	{
		ft_rrr(from, to, rep_1);
		ft_rrb(to, rep_2 - rep_1);
	}
}
