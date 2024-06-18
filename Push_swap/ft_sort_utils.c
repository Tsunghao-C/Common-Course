/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:56:48 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/18 23:51:14 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_list *lst)
{
	int	max;

	max = ft_peek(lst);
	while (lst)
	{
		if (ft_peek(lst) > max)
			max = ft_peek(lst);
		lst = lst->next;
	}
	return (max);
}

int	ft_min(t_list *lst)
{
	int	min;

	min = ft_peek(lst);
	while (lst)
	{
		if (ft_peek(lst) < min)
			min = ft_peek(lst);
		lst = lst->next;
	}
	return (min);
}

int	ft_target_ba(t_list *lst, int ref)
{
	int	target;

	target = ft_max(lst);
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

	target = ft_max(lst);
	while (lst)
	{
		if ((ref - ft_peek(lst)) > 0 && (ft_peek(lst) < target))
			target = ft_peek(lst);
		lst = lst->next;
	}
	return (target);
}

int	ft_is_rotate(t_list *lst, int target)
{
	t_list	*tmp;
	int	i;

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
			ft_ra(to);
		else
			ft_rra(to);
	}
}

void	ft_push_checka2b(t_list **from, t_list **to)
{
	int	src;
	int	target;

	src = ft_peek(*from);
	if (src > ft_max(*to) || src < ft_min(*to))
		target = ft_max(*to);
	else
		target = ft_target_ab(*to, src);
	while (ft_peek(*to) != target)
	{
		if (ft_is_rotate(*to, target))
			ft_ra(to);
		else
			ft_rra(to);
	}
}

void	ft_sort_stk_a(t_list **stk_a)
{
	int	min;

	min = ft_min(*stk_a);
	while (ft_peek(*stk_a) != min)
	{
		if (ft_is_rotate(*stk_a, min))
			ft_ra(stk_a);
		else
			ft_rra(stk_a);
	}
}
