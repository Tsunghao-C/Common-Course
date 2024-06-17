/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:03:15 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/17 12:16:25 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cmp(t_list *lst)
{
	int	a;
	int	b;

	if (!((*lst)->next))
		return (-1);
	a = ft_atoi((char *)((*lst)->content));
	b = ft_atoi((char *)((*lst)->next->content));
	return (a - b);
}

void	ft_2nodes_sort(t_list **stk_a)
{
	if (ft_cmp(*stk_a) > 0)
		ft_sa(stk_a);
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
