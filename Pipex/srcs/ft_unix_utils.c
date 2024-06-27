/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:38:02 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/27 11:42:49 by tsuchen          ###   ########.fr       */
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

void	ft_do_pipe(char *cmd, char **env)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		ft_err2_pipe(errno);
	pid = fork();
	if (pid == -1)
		ft_err4_fork(errno);
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], OUT);
		close(fd[1]);
		if (ft_exec(cmd, env) < 0)
			exit(6);
		return ;
	}
	close(fd[1]);
	dup2(fd[0], IN);
	close(fd[0]);
}

void	ft_do_fork_main(char *cmd, char **env)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_err4_fork(errno);
	if (!pid)
	{
		if (ft_exec(cmd, env) < 0)
			exit(6);
		return ;
	}
	close(IN);
	close(OUT);
}

void	ft_err6_cmd(char *path, int err_no)
{
	dup2(ERR, OUT);
	if (ft_isabs_path(path) == 1)
		ft_printf("%s: %s: %s\n", P_NAME, strerror(err_no), path);
	else
		ft_printf("%s: command not found: %s\n", P_NAME, path);
}
