/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:09:37 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/20 02:01:09 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_ra(t_list **stk_a, t_list **stk_b)
{
	while (*stk_b)
		break ;
	if (!(*stk_a))
		return ;
	ft_rotate(stk_a);
}

void	ft_rb(t_list **stk_a, t_list **stk_b)
{
	while (*stk_a)
		break ;
	if (!(*stk_b))
		return ;
	ft_rotate(stk_b);
}

void	ft_rr(t_list **stk_a, t_list **stk_b)
{
	if (!(*stk_a) || !(*stk_b))
		return ;
	ft_rotate(stk_a);
	ft_rotate(stk_b);
}
