/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2nodes_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:03:15 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/16 21:07:56 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_2nodes_sort(t_list **stk_a)
{
	int	a;
	int	b;

	a = ft_atoi((char *)((*stk_a)->content));
	b = ft_atoi((char *)((*stk_a)->next->content));
	if (a > b)
		ft_sa(stk_a);
}
