/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:56:48 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/17 19:05:12 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_list *lst)
{
	int	max;
	t_list	*tmp;

	tmp = lst;
	max = ft_peek(tmp);
	while (tmp)
	{
		if (ft_peek(tmp) > max)
			max = ft_peek(tmp);
		tmp = tmp->next;
	}
	return (max);
}

int	ft_min(t_list *lst)
{
	int	min;
	t_list	*tmp;

	tmp = lst;
	min = ft_peek(tmp);
	while (tmp)
	{
		if (ft_peek(tmp) < min)
			min = ft_peek(tmp);
		tmp = tmp->next;
	}
	return (min);
}
int	ft_is_rotate(t_list *lst)
{
	t_list	*tmp;
	int	i;
	int	min;

	i = 0;
	min = ft_min(lst);
	tmp = lst;
	while (tmp)
	{
		if (ft_peek(tmp) == min)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i > (ft_lstsize(lst) - i))
		return (0);
	else
		return (1);
}
void	ft_push_check(t_list **from, t_list **to)
{
	int	src;

	src = ft_peek(*from);
	if (src > ft_max(*to) || src < ft_min(*to))
	{
		while (ft_peek(*to) != ft_min(*to))
		{
			if (ft_is_rotate(*to))
				ft_ra(to);
			else
				ft_rra(to);
		}
	}
	else
	{
		while (!((src < ft_peek(*to) && src > ft_peek(ft_lstlast(*to)))))
			ft_ra(to);
	}
}

void	ft_sort_stk_a(t_list **stk_a)
{
	int	min;

	min = ft_min(*stk_a);
	while (ft_peek(*stk_a) != min)
	{
		if (ft_is_rotate(*stk_a))
			ft_ra(stk_a);
		else
			ft_rra(stk_a);
	}
}
