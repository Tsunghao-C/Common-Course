/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:38:02 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/23 01:40:11 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_others(int fd[][2], int rep, int n_pipes)
{
	int	i;

	i = 0;
	while (i < n_pipes)
	{
		if (i != rep)
			close(fd[i][0]);
		if (!(i == rep + 1 || (rep + 1 == n_pipes && i == 0)))
			close(fd[i][1]);
		i++;
	}
}

void	ft_read_n_write(char *file_in, int fd_pw)
{
	int	fd;
	char	buffer[BUFF + 1];
	int	nu_r;

	fd = open(file_in, O_RDONLY);
	if (fd == -1)
		ft_err3_open(errno, file_in);
	nu_r = 1;
	while (nu_r > 0)
	{
		nu_r = read(fd, buffer, BUFF);
		if (nu_r == -1)
			return ;
		buffer[nu_r] = '\0';
		if (write(fd_pw, buffer, nu_r) < 0)
			return ;
		ft_bzero(buffer, BUFF);
	}
	close(fd);
}

void	ft_read_n_write2(char *file_out, int fd_pr)
{
	int	fd;
	char	buffer[BUFF + 1];
	int	nu_r;

	fd = open(file_out, O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
		ft_err3_open(errno, file_out);
	nu_r = 1;
	while (nu_r > 0)
	{
		nu_r = read(fd_pr, buffer, BUFF);
		if (nu_r == -1)
			return ;
		buffer[nu_r] = '\0';
		if (write(fd, buffer, nu_r) < 0)
			return ;
		ft_bzero(buffer, BUFF);
	}
	close(fd);
}

void	ft_wait_all(int childs, int *pid)
{
	int	i;

	i = 0;
	while (i < childs)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
}

void	ft_init_pipe(int fd[][2], int n_pipes)
{
	int	i;

	i = 0;
	while (i < n_pipes)
	{
		if (pipe(fd[i++]) < 0)
			ft_err2_pipe(errno);
	}
}

int	ft_do_child(int fd[][2], int ac, char **av, int *pid)
{
	int	i;
	char	**cmd;

	i = -1;
	while (++i < ac - 3)
	{
		if (pid[i] == 0)
		{
			ft_printf("child %d, pid is %d\n", i, pid[i]);
			ft_close_others(fd, i, ac - 2);
			cmd = ft_split(av[i + 2], ' ');
			if (!cmd)
				ft_err6_malloc(i, pid[i]);
			dup2(fd[i][0], IN);
			close(fd[i][0]);
			dup2(fd[i + 1][1], OUT);
			close(fd[i + 1][1]);
			execve(cmd[0], cmd, NULL);
			ft_free_all(cmd);
			return (0);
		}
	}
	return (0);
}

int	ft_do_parent(int fd[][2], int ac, char **av)
{
	ft_close_others(fd, ac - 3, ac - 2);
	ft_read_n_write(av[1], fd[0][1]);
	close(fd[0][1]);
	ft_read_n_write2(av[ac - 1], fd[ac - 3][0]);
	close(fd[ac - 3][0]);
	return (0);
}
