/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:56:48 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/19 18:46:15 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_loc(t_list *lst, int target)
{
	int	tar_loc;

	tar_loc = 0;
	while (lst && ft_peek(lst) != target)
	{
		tar_loc++;
		lst = lst->next;
	}
	return (tar_loc);
}

int	ft_is_rotate(t_list *lst, int target)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (ft_peek(tmp) == target)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i > (ft_lstsize(lst) - i))
		return (0);
	else
		return (1);
}

void	ft_sort_stk_a(t_list **stk_a)
{
	int	min;

	min = ft_min(*stk_a);
	while (ft_peek(*stk_a) != min)
	{
		if (ft_is_rotate(*stk_a, min))
			ft_ra(stk_a, 1);
		else
			ft_rra(stk_a, 1);
	}
}
