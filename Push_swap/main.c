/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:23:11 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/18 23:55:26 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_all(char **av, int nodes)
{
	int	i;

	i = 0;
	while (i < nodes)
		free(av[i++]);
	free(av);
}

static int	ft_is_sorted(t_list *lst)
{
	int	ref;

	ref = ft_peek(lst);
	while (lst->next)
	{
		if (ft_peek(lst->next) < ref)
			return (0);
		ref = ft_peek(lst->next);
		lst = lst->next;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_list	*stk_a;
	t_list	*stk_b;
	int		nodes;

	stk_a = NULL;
	stk_b = NULL;
	if (ac <= 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	ft_arg_check(av);
	ft_init_stk(&stk_a, av, &ft_del);
	nodes = ft_lstsize(stk_a);
	//ft_printf("before sort:\n");
	//ft_print_all(stk_a);
	if (!ft_is_sorted(stk_a))
	{
		if (nodes <= 5)
			ft_tiny_sort(&stk_a, &stk_b, nodes);
		else
			ft_sort_list(&stk_a, &stk_b, nodes);
	}
	//ft_printf("after sort:\n");
	//ft_print_all(stk_a);
	ft_lstclear(&stk_a, &ft_del);
	if (ac == 2)
		ft_free_all(av, nodes);
	return (0);
}
