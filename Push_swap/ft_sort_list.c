/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:18:35 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/19 13:06:23 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_list(t_list **stk_a, t_list **stk_b, int size)
{
	int	cnt;

	cnt = 0;
	while (cnt < 2)
	{
		ft_pb(stk_a, stk_b);
		cnt++;
	}
	while (size - cnt++ > 3)
	{
		ft_push_checka2b(stk_a, stk_b);
		ft_pb(stk_a, stk_b);
	}
	ft_3nodes_sort(stk_a);
	while (*stk_b)
	{
		ft_push_checkb2a(stk_b, stk_a);
		ft_pa(stk_b, stk_a);
	}
	ft_sort_stk_a(stk_a);
}

int	ft_cal_steps(t_list *from, int loc, int size, t_list *to)
{
	int	target;
	int	tar_loc;

	target = ft_target_ab(to, ft_peek(from));
	tar_loc = ft_get_loc(to, target);
	if (loc == 0)
		return (ft_smaller(tar_loc, ft_lstsize(to) - tar_loc));
	else if (tar_loc == 0)
		return (ft_smaller(loc, size - loc);
	else if (size - loc > loc && ft_lstsize(to) - tar_loc > tar_loc)
		return (ft_bigger(loc, tar_loc));
	else if (size - loc < loc && ft_lstsize(to) - tar_loc < tar_loc)
		return (ft_bigger(size - loc, ft_lstsize(to) - tar_loc));
	else
		return (ft_smaller(loc, size - loc)
			+ ft_smaller(tar_loc, ft_lstsize(to) - tar_loc));
}

int	ft_find_cheapest(t_list *from, int size, t_list *to)
{
	t_list	*tmp;
	int	cheapest;
	int	step;
	int	i;

	i = 0;
	tmp = from;
	cheapest = ft_cal_steps(from, i, size, to);
	while (i < size)
	{
		step = ft_cal_steps(from, i, size, to);
		if (step < cheapest)
		{
			cheapest = step;
			tmp = from;
		}
		i++;
		from = from->next;
	}
	return (ft_peek(tmp));
}

void	ft_cheap_checka2b(t_list **from, int size, t_list **to)
{
	int	tar_loc;
	int	chp_loc;
	int	to_size;

	chp_loc = ft_get_loc(*from, ft_find_cheapest(*from, size, *to));
	tar_loc = ft_get_loc(*to, ft_target_ab(*to, ft_find_cheapest(*from, size, *to)));
	to_size = ft_lstsize(*to);
	if (chp_loc == 0)
	{
		if (to_size - tar_loc > tar_loc)
			ft_rb(to, tar_loc);
		else
			ft_rrb(to, to_size - tar_loc);
	}
	else if (tar_loc == 0)
	{
		if (size - chp_loc > chp_loc)
			ft_ra(from, chp_loc);
		else
			ft_rra(from, size - chp_loc);
	}
	else if (size - chp_loc > chp_loc && to_size - tar_loc > tar_loc)
	{
		if (chp_loc > tar_loc)
		{
			ft_rr(from, to, tar_loc);
			ft_ra(from, chp_loc - tar_loc);
		}
		else
		{
			ft_rr(from, to, chp_loc);
			ft_rb(to, tar_loc - chp_loc);
		}
	}
	else if (size - chp_loc < chp_loc && to_size - tar_loc < tar_loc)
	{
		if (size - chp_loc > to_size - tar_loc)
		{
			ft_rrr(from, to, to_size - tar_loc);
			ft_rra(from, ((size - chp_loc) - (to_size - tar_loc)));
		}
		else
		{
			ft_frr(from, to, size - chp_loc);
			ft_rrb(to, ((to_size - tar_loc) - (size - chp_loc)));
		}
	}
	else
	{

	}
}
