/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:43:20 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/19 18:53:08 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_target_ba(t_list *lst, int ref)
{
	int	target;

	target = ft_max(lst);
	if (target < ref)
		return (ft_min(lst));
	while (lst)
	{
		if ((ft_peek(lst) - ref) > 0 && (ft_peek(lst) < target))
			target = ft_peek(lst);
		lst = lst->next;
	}
	return (target);
}

int	ft_target_ab(t_list *lst, int ref)
{
	int	target;

	target = ft_min(lst);
	if (ref < target)
		return (ft_max(lst));
	while (lst)
	{
		if ((ref - ft_peek(lst)) > 0 && (ft_peek(lst) > target))
			target = ft_peek(lst);
		lst = lst->next;
	}
	return (target);
}

void	ft_push_checkb2a(t_list **from, t_list **to)
{
	int	src;
	int	target;

	src = ft_peek(*from);
	if (src > ft_max(*to) || src < ft_min(*to))
		target = ft_min(*to);
	else
		target = ft_target_ba(*to, src);
	while (ft_peek(*to) != target)
	{
		if (ft_is_rotate(*to, target))
			ft_ra(to, 1);
		else
			ft_rra(to, 1);
	}
}
