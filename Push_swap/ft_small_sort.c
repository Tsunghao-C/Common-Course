/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:03:15 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/19 13:06:05 by tsuchen          ###   ########.fr       */
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
	int	max;

	max = ft_max(*stk_a);
	if (ft_peek(*stk_a) == max)
		ft_ra(stk_a);
	else if (ft_peek((*stk_a)->next) == max)
		ft_rra(stk_a);
	if (ft_cmp(*stk_a) > 0)
		ft_sa(stk_a);
}

void	ft_tiny_sort(t_list **stk_a, t_list **stk_b, int nodes)
{
	if (nodes == 2)
		ft_sa(stk_a);
	else if (nodes == 3)
		ft_3nodes_sort(stk_a);
	else
	{
		while (nodes-- > 3)
			ft_pb(stk_a, stk_b);
		ft_3nodes_sort(stk_a);
		while (*stk_b)
		{
			ft_push_checkb2a(stk_b, stk_a);
			ft_pa(stk_b, stk_a);
		}
		ft_sort_stk_a(stk_a);
	}
}
