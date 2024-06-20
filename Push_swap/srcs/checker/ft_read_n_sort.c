/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_n_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:14:55 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/20 01:37:10 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_read_n_sort(t_list **stk_a, t_list **stk_b)
{
	char	*line;
	void	*oprs;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		oprs = ft_check_op(line);
		if (!oprs)
		{
			free(line);
			write(STDERR_FILENO, "Error\n", 6);
			return (0);
		}
		ft_do_op(stk_a, stk_b, oprs);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (1);
}

void	ft_do_op(t_list **a, t_list **b, void (*f)(t_list **, t_list **))
{
	f(a, b);
}

void	*ft_check_op(char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		return (&ft_sa);
	else if (!ft_strcmp(str, "sb\n"))
		return (&ft_sb);
	else if (!ft_strcmp(str, "ss\n"))
		return (&ft_ss);
	else if (!ft_strcmp(str, "pa\n"))
		return (&ft_pa);
	else if (!ft_strcmp(str, "pb\n"))
		return (&ft_pb);
	else if (!ft_strcmp(str, "ra\n"))
		return (&ft_ra);
	else if (!ft_strcmp(str, "rb\n"))
		return (&ft_rb);
	else if (!ft_strcmp(str, "rr\n"))
		return (&ft_rr);
	else if (!ft_strcmp(str, "rra\n"))
		return (&ft_rra);
	else if (!ft_strcmp(str, "rrb\n"))
		return (&ft_rrb);
	else if (!ft_strcmp(str, "rrr\n"))
		return (&ft_rrr);
	else
		return (NULL);
}
