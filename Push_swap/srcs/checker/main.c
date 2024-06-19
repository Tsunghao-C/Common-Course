/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:39:02 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/19 19:54:52 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_free_all(char **av, int nodes)
{
	int	i;

	i = 0;
	while (i < nodes)
		free(av[i++]);
	free(av);
}

int	main(int ac, char *av[])
{
	t_list	*stk_a;
	t_list	*stk_b;
	int		nodes;

	stk_a = NULL;
	stk_b = NULL;
	if (ac <= 1 || (ac == 2 ** !av[1][0]))
		return (0);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	ft_arg_check(av);
	ft_init_stk(&stk_a, av, &ft_del);
	nodes = ft_lstsize(stk_a);
	// checker operations
	if (ft_is_sorted(stk_a))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	ft_lstclear(&stk_a, &ft_del);
	if (ac == 2)
		ft_free_all(av, nodes);
	return (0);
}
