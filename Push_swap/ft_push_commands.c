/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:55:54 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/16 20:08:31 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	ft_lstadd_front(dst, tmp);
}

void	ft_pa(t_list **stk_b, t_list **stk_a)
{
	if (!(*stk_b))
		return ;
	ft_push(stk_b, stk_a);
	write(STDOUT_FILENO, "pa\n", 3);
}

void	ft_pb(t_list **stk_a, t_list **stk_b)
{
	if (!(*stk_a))
		return ;
	ft_push(stk_a, stk_b);
	write(STDOUT_FILENO, "pb\n", 3);
}
