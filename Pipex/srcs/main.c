/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:41:35 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/23 01:22:37 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_all(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	main(int ac, char *av[])
{
	if (ac < 5)
		ft_err1_argc(ac);
	int	fd[ac - 2][2];
	int	pid[ac - 3];
	int	i;

	ft_init_pipe(fd, ac - 2);
	i = 0;
	while (i < ac - 3)
	{
		pid[i] = fork();
		if (pid[i++] == -1)
			ft_err4_fork(errno);
	}
	ft_do_child(fd, ac, av, pid);
	ft_do_parent(fd, ac, av);
	ft_wait_all(ac - 3, pid);
	return (0);
}
