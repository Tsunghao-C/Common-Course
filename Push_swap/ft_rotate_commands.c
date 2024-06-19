/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:09:37 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/19 18:22:43 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	if (*lst)
		(*lst)->prev = NULL;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
}

void	ft_ra(t_list **stk_a, int rep)
{
	if (!(*stk_a) || !rep)
		return ;
	ft_rotate(stk_a);
	write(STDOUT_FILENO, "ra\n", 3);
	ft_ra(stk_a, rep - 1);
}

void	ft_rb(t_list **stk_b, int rep)
{
	if (!(*stk_b) || !rep)
		return ;
	ft_rotate(stk_b);
	write(STDOUT_FILENO, "rb\n", 3);
	ft_rb(stk_b, rep - 1);
}

void	ft_rr(t_list **stk_a, t_list **stk_b, int rep)
{
	if (!(*stk_a) || !(*stk_b) || !rep)
		return ;
	ft_rotate(stk_a);
	ft_rotate(stk_b);
	write(STDOUT_FILENO, "rr\n", 3);
	ft_rr(stk_a, stk_b, rep - 1);
}

void	ft_combo_rr_rx(t_list **from, t_list **to, int rep_1, int rep_2)
{
	if (rep_1 > rep_2)
	{
		ft_rr(from, to, rep_2);
		ft_ra(from, rep_1 - rep_2);
	}
	else
	{
		ft_rr(from, to, rep_1);
		ft_rb(to, rep_2 - rep_1);
	}
}
