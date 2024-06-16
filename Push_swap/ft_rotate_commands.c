/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:09:37 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/16 20:41:37 by tsuchen          ###   ########.fr       */
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
	ft_lstadd_back(lst, tmp);
}

void	ft_ra(t_list **stk_a)
{
	if (!(*stk_a))
		return ;
	ft_rotate(stk_a);
	write(STDOUT_FILENO, "ra\n", 3);
}

void	ft_rb(t_list **stk_b)
{
	if (!(*stk_b))
		return ;
	ft_rotate(stk_b);
	write(STDOUT_FILENO, "rb\n", 3);
}

void	ft_rr(t_list **stk_a, t_list **stk_b)
{
	if (!(*stk_a))
		return ;
	if (!(*stk_b))
		return ;
	ft_rotate(stk_a);
	ft_rotate(stk_b);
	write(STDOUT_FILENO, "rr\n", 3);
}
