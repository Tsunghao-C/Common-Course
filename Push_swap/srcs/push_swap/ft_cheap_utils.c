/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:31:39 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/19 18:34:26 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cal_steps_ab(t_list *from, int loc, int size, t_list *to)
{
	int	target;
	int	tar_loc;

	target = ft_target_ab(to, ft_peek(from));
	tar_loc = ft_get_loc(to, target);
	if (size - loc > loc && ft_lstsize(to) - tar_loc > tar_loc)
		return (ft_bigger(loc, tar_loc));
	else if (size - loc < loc && ft_lstsize(to) - tar_loc < tar_loc)
		return (ft_bigger(size - loc, ft_lstsize(to) - tar_loc));
	else
		return (ft_smaller(loc, size - loc)
			+ ft_smaller(tar_loc, ft_lstsize(to) - tar_loc));
}

int	ft_find_cheapest_ab(t_list *from, int size, t_list *to)
{
	t_list	*tmp;
	int		cheapest;
	int		step;
	int		i;

	i = 0;
	tmp = from;
	cheapest = ft_cal_steps_ab(from, i, size, to);
	while (i < size)
	{
		step = ft_cal_steps_ab(from, i, size, to);
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

int	ft_cal_steps_ba(t_list *from, int loc, int size, t_list *to)
{
	int	target;
	int	tar_loc;

	target = ft_target_ba(to, ft_peek(from));
	tar_loc = ft_get_loc(to, target);
	if (size - loc > loc && ft_lstsize(to) - tar_loc > tar_loc)
		return (ft_bigger(loc, tar_loc));
	else if (size - loc < loc && ft_lstsize(to) - tar_loc < tar_loc)
		return (ft_bigger(size - loc, ft_lstsize(to) - tar_loc));
	else
		return (ft_smaller(loc, size - loc)
			+ ft_smaller(tar_loc, ft_lstsize(to) - tar_loc));
}

int	ft_find_cheapest_ba(t_list *from, int size, t_list *to)
{
	t_list	*tmp;
	int		cheapest;
	int		step;
	int		i;

	i = 0;
	tmp = from;
	cheapest = ft_cal_steps_ba(from, i, size, to);
	while (i < size)
	{
		step = ft_cal_steps_ba(from, i, size, to);
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
