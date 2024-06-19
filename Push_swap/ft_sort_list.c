/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:18:35 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/19 10:31:28 by tsuchen          ###   ########.fr       */
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
