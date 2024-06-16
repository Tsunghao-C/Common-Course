/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:23:11 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/16 18:40:52 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_list	*stk_a;
	t_list	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (ac <= 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	ft_arg_check(av);
	ft_init_stk(&stk_a, av, ft_del);
	ft_sort_list(stack_a, stack_b);
	free_all(stack_a);
	return (0);
}
