/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:03:15 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/17 18:45:50 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_peek(t_list *lst)
{
	return (ft_atoi((char *)(lst->content)));
}

int	ft_cmp(t_list *lst)
{
	if (!(lst->next))
		return (-1);
	return (ft_peek(lst) - ft_peek(lst->next));
}

void	ft_3nodes_sort(t_list **stk_a)
{
	t_list	*tmp;

	tmp = *stk_a;
	while (tmp)
	{
		if (!(tmp->prev) && ft_cmp(tmp) > 0)
		{
			ft_sa(stk_a);
			tmp = *stk_a;
		}
		else if (ft_cmp(tmp) > 0)
		{
			ft_rra(stk_a);
			tmp = *stk_a;
		}
		else
			tmp = tmp->next;
	}
}

void	ft_tiny_sort(t_list **stk_a, t_list **stk_b, int nodes)
{
	if (nodes <= 3)
		ft_3nodes_sort(stk_a);
	else
	{
		while (nodes-- > 3)
			ft_pb(stk_a, stk_b);
		ft_3nodes_sort(stk_a);
		while (*stk_b)
		{
			ft_push_check(stk_b, stk_a);
			ft_pa(stk_b, stk_a);
		}
		ft_sort_stk_a(stk_a);
	}
}
