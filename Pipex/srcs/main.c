/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:41:35 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/25 18:14:37 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			perror("exec");
		return ;
	}
	close(fd[1]);
	dup2(fd[0], IN);
	close(fd[0]);
	waitpid(pid, NULL, 0);
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
			perror("exec");
		return ;
	}
	waitpid(pid, NULL, 0);
}

int	ft_init_here_doc(char *file, char *eof)
{
	int		fd;
	char	*limiter;
	char	*line;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		ft_err3_open(errno, file);
	limiter = ft_strjoin(eof, "\n");
	line = get_next_line(IN);
	while (line)
	{
		if (!strcmp(line, limiter))
		{
			free(line);
			break ;
		}
		if (write(fd, line, ft_strlen(line)) < 0)
			ft_err5_write(errno, file, line);
		free(line);
		line = get_next_line(IN);
	}
	free(limiter);
	close(fd);
	return (open(file, O_RDONLY));
}

int	ft_init_fdio(int *fd_in, int *fd_out, int ac, char **av)
{
	if (!strcmp(av[1], "here_doc"))
	{
		*fd_in = ft_init_here_doc(av[1], av[2]);
		*fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		return (3);
	}
	else
	{
		*fd_in = open(av[1], O_RDONLY);
		*fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		return (2);
	}
}

int	main(int ac, char *av[], char **env)
{
	int	fd_in;
	int	fd_out;
	int	i;

	if (ac < 5 || (!strcmp(av[1], "here_doc") && ac < 6))
		ft_err1_argc(ac);
	i = ft_init_fdio(&fd_in, &fd_out, ac, av);
	if (fd_in == -1 || fd_out == -1)
		ft_err3_open(errno, av[1]);
	dup2(fd_in, IN);
	close(fd_in);
	while (i < ac - 2)
		ft_do_pipe(av[i++], env);
	dup2(fd_out, OUT);
	close(fd_out);
	ft_do_fork_main(av[i], env);
	if (!ft_strcmp(av[1], "here_doc"))
		unlink(av[1]);
	return (0);
}
