/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:40:30 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/19 18:41:43 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_peek(t_list *lst)
{
	return (ft_atoi((char *)(lst->content)));
}

int	ft_bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_smaller(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

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
