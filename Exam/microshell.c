/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:42:37 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/10 00:39:42 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_err(char *s)
{
	write(STDERR_FILENO, s, ft_strlen(s));
}

char	*get_home(char **envp)
{
	int	i;
	char	*path;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (!strncmp(envp[i], "HOME", 4))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

int	do_cd(char *av[], char **envp)
{
	int	i;
	char	*home;

	i = 0;
	home = get_home(envp);
	while (av[1 + i])
		i++;
	if (i > 2)
	{
		print_err("error: cd: bad arguments\n");
		return (1);
	}
	if (i == 1 || (i == 2 && !strcmp(av[2], "--")))
	{
		if (!home)
		{
			print_err("error: cd: cannot change directory to HOME\n");
			return (1);
		}
		chdir(home);
	}
	else if (chdir(av[2]) < 0)
	{
		print_err("error: cd: cannot change directory to ");
		print_err(av[2]);
		print_err("\n");
		return (1);
	}
	printf("ready to cd, path is %s\n", av[2]);
	return (0);
}

void	do_pipe(int fd[2])
{
	if (pipe(fd) == -1)
	{
		print_err("error: fatal\n");
		exit(1);
	}
}

void	do_child(char *av[], char **envp, int end, int fd[2])
{
	if (fd[0] != -1 && fd[1] != -1)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	av[end] = 0;
	if (execve(*av, av, envp) == -1)
	{
		print_err("error: cannot execute ");
		print_err(*av);
		print_err("\n");
		exit(1);
	}
}

int	do_exec(char *av[], char **envp, int end, int has_pipe)
{
	int	fd[2];
	int	status;
	pid_t	pid;

	fd[0] = -1;
	fd[1] = -1;
	if (has_pipe == 1)
		do_pipe(fd);
	pid = fork();
	if (pid == -1)
	{
		print_err("error: fatal\n");
		exit(1);
	}
	if (!pid)
		do_child(av, envp, end, fd);
	else
	{
		waitpid(pid, &status, 0);
		if (has_pipe == 1)
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
		}
	}
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int ac, char *av[], char **envp)
{
	int	i;
	int	has_pipe;
	if (ac < 2)
		return (0);
	if (!strcmp(av[1], "cd"))
	{
		if (do_cd(av, envp))
			return (1);
		return (0);
	}
	i = 0;
	while (av[i])
	{
		av += i + 1;
		has_pipe = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (av[i] && !strcmp(av[i], "|"))
			has_pipe = 1;
		do_exec(av, envp, i, has_pipe);
		if (!av[i])
			break ;
	}
	return (0);
}
