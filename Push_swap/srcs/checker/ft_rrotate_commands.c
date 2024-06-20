/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:20:59 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/20 02:01:35 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_rra(t_list **stk_a, t_list **stk_b)
{
	while (*stk_b)
		break ;
	if (!(*stk_a))
		return ;
	ft_rrotate(stk_a);
}

void	ft_rrb(t_list **stk_a, t_list **stk_b)
{
	while (*stk_a)
		break ;
	if (!(*stk_b))
		return ;
	ft_rrotate(stk_b);
}

void	ft_rrr(t_list **stk_a, t_list **stk_b)
{
	if (!(*stk_a) || !(*stk_b))
		return ;
	ft_rrotate(stk_a);
	ft_rrotate(stk_b);
}
