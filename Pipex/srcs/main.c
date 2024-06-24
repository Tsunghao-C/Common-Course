/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:41:35 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/24 19:02:18 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

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
	char	**argv;
	int		fd[MAX_FD][2];
	int		pid[MAX_FD];
	int		argv_len;

	if (ac < 5)
		ft_err1_argc(ac);
	argv = ft_av_check(ac, av);
	if (!argv)
		return (0);
	argv_len = ft_arrlen(argv);
	ft_init_pipe(fd, argv_len - 2);
	ft_do_child(fd, argv_len, argv, pid);
	ft_do_parent(fd, argv_len, argv);
	ft_wait_all(argv_len - 3, pid);
	ft_free_all(argv);
	if (!ft_strcmp(av[1], "here_doc"))
	{
		if (unlink(av[1]) < 0)
			ft_err8_unlink(errno);
	}
	return (0);
}
