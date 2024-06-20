/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:39:02 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/20 14:35:40 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free_all(char **av)
{
	int	i;

	i = 0;
	while (av[i])
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

static void	ft_clear_list(t_list **a, t_list **b)
{
	ft_lstclear(a, &ft_del);
	ft_lstclear(b, &ft_del);
}

static void	ft_init(t_list **a, t_list **b)
{
	*a = NULL;
	*b = NULL;
}

int	main(int ac, char *av[])
{
	t_list	*stk_a;
	t_list	*stk_b;

	ft_init(&stk_a, &stk_b);
	if (ac < 2 || (ac == 2 && !av[1][0]))
	{
		if (ac == 2)
			write(STDERR_FILENO, "Error\n", 6);
		return (0);
	}
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	ft_arg_check(ac, av);
	ft_init_stk(&stk_a, ac, av, &ft_del);
	if (ft_read_n_sort(&stk_a, &stk_b))
	{
		if (ft_is_sorted(stk_a) && !stk_b)
			write(STDOUT_FILENO, "OK\n", 3);
		else
			write(STDOUT_FILENO, "KO\n", 3);
	}
	ft_clear_list(&stk_a, &stk_b);
	if (ac == 2)
		ft_free_all(av);
	return (0);
}
