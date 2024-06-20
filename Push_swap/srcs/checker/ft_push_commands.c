/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:55:54 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/20 01:09:52 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	ft_lstadd_front(dst, tmp);
}

void	ft_pa(t_list **stk_a, t_list **stk_b)
{
	if (!(*stk_b))
		return ;
	ft_push(stk_b, stk_a);
}

void	ft_pb(t_list **stk_a, t_list **stk_b)
{
	if (!(*stk_a))
		return ;
	ft_push(stk_a, stk_b);
}
