/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:23:11 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/15 17:04:25 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	if (ac < 2)
		return (0);
	int	elem_cn;

	elem_cn = ft_arg_check(av);
	if (elem_cn < 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (0);
	}

}
