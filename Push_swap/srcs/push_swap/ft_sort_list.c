/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:18:35 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/19 18:35:39 by tsuchen          ###   ########.fr       */
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
	while (size - cnt > 3)
	{
		ft_cheap_checka2b(stk_a, size - cnt, stk_b, cnt);
		ft_pb(stk_a, stk_b);
		cnt++;
	}
	ft_3nodes_sort(stk_a);
	while (cnt > 0)
	{
		ft_cheap_checkb2a(stk_b, cnt, stk_a, (size - cnt));
		ft_pa(stk_b, stk_a);
		cnt--;
	}
	ft_sort_stk_a(stk_a);
}

void	ft_cheap_checka2b(t_list **from, int size, t_list **to, int to_size)
{
	int	chp_loc;
	int	tar_loc;

	chp_loc = ft_get_loc(*from, ft_find_cheapest_ab(*from, size, *to));
	tar_loc = ft_get_loc(*to,
			ft_target_ab(*to, ft_find_cheapest_ab(*from, size, *to)));
	if (size - chp_loc > chp_loc && to_size - tar_loc > tar_loc)
		ft_combo_rr_rx(from, to, chp_loc, tar_loc);
	else if (size - chp_loc < chp_loc && to_size - tar_loc < tar_loc)
		ft_combo_rrr_rrx(from, to, (size - chp_loc), (to_size - tar_loc));
	else
	{
		if (to_size - tar_loc > tar_loc)
			ft_rb(to, tar_loc);
		else
			ft_rrb(to, to_size - tar_loc);
		if (size - chp_loc > chp_loc)
			ft_ra(from, chp_loc);
		else
			ft_rra(from, size - chp_loc);
	}
}

void	ft_cheap_checkb2a(t_list **from, int size, t_list **to, int to_size)
{
	int	chp_loc;
	int	tar_loc;

	chp_loc = ft_get_loc(*from, ft_find_cheapest_ba(*from, size, *to));
	tar_loc = ft_get_loc(*to,
			ft_target_ba(*to, ft_find_cheapest_ba(*from, size, *to)));
	if (size - chp_loc > chp_loc && to_size - tar_loc > tar_loc)
		ft_combo_rr_rx(to, from, tar_loc, chp_loc);
	else if (size - chp_loc < chp_loc && to_size - tar_loc < tar_loc)
		ft_combo_rrr_rrx(to, from, (to_size - tar_loc), (size - chp_loc));
	else
	{
		if (to_size - tar_loc > tar_loc)
			ft_ra(to, tar_loc);
		else
			ft_rra(to, to_size - tar_loc);
		if (size - chp_loc > chp_loc)
			ft_rb(from, chp_loc);
		else
			ft_rrb(from, size - chp_loc);
	}
}
