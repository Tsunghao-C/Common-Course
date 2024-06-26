/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:38:02 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/25 14:06:40 by tsuchen          ###   ########.fr       */
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
	char	buffer[BUFF + 1];
	int		fd;
	int		nu_r;

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

void	ft_read_n_write2(char *file_out, int fd_pr, int mode)
{
	char	buffer[BUFF + 1];
	int		fd;
	int		nu_r;

	if (mode == 1)
		fd = open(file_out, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
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

char	**ft_get_allpath(char **env)
{
	int		i;
	char	*path_all;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path_all = ft_strtrim(env[i], "PATH=");
			paths = ft_split(path_all, ':');
			free(path_all);
			return (paths);
		}
		i++;
	}
	return (NULL);
}

char	*ft_get_path(char *file, char **env)
{
	char	**paths;
	char	*path;
	char	*exec;
	int		i;

	paths = ft_get_allpath(env);
	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(path, file);
		free(path);
		if (!access(exec, X_OK | F_OK))
		{
			ft_free_all(paths);
			return (exec);
		}
		free(exec);
	}
	ft_free_all(paths);
	return (ft_strdup(file));
}

int	ft_exec(char *av, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	if (!cmd)
		return (-1);
	path = ft_get_path(cmd[0], env);
	if (execve(path, cmd, env) == -1)
	{
		ft_err9_access(errno, path);
		ft_free_all(cmd);
		free(path);
		exit(9);
	}
	ft_free_all(cmd);
	free(path);
	return (0);
}

int	ft_do_child(int fd[][2], int *pid, char **av, char **env)
{
	int		i;
	int		ac;

	ac = ft_arrlen(av);
	i = -1;
	while (++i < ac - 3)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			ft_err4_fork(errno);
		if (pid[i] == 0)
		{
			ft_close_others(fd, i, ac - 2);
			dup2(fd[i][0], IN);
			close(fd[i][0]);
			dup2(fd[i + 1][1], OUT);
			close(fd[i + 1][1]);
			if (ft_exec(av[i + 2], env) == -1)
				ft_err6_malloc(i, pid[i]);
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
	if (!ft_strcmp(av[1], "here_doc"))
		ft_read_n_write2(av[ac - 1], fd[ac - 3][0], 1);
	else
		ft_read_n_write2(av[ac - 1], fd[ac - 3][0], 0);
	close(fd[ac - 3][0]);
	return (0);
}

int	ft_init_argv(char **argv, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		if (j == 2 && !strcmp(av[1], "here_doc"))
			j++;
		argv[i] = ft_strdup(av[j++]);
		if (!argv[i++])
		{
			ft_free_all(argv);
			return (-1);
		}
	}
	argv[i] = NULL;
	return (0);
}

char	**ft_av_check(int ac, char **av)
{
	char	**argv;

	if (strcmp(av[1], "here_doc") == 0)
	{
		if (ac < 6)
			ft_err1_argc(ac);
		if (ft_init_here_doc(av[1], av[2]))
			return (NULL);
		ac -= 1;
	}
	else if (open(av[1], O_WRONLY) < 0)
		ft_err3_open(errno, av[1]);
	argv = (char **)malloc((ac + 1) * sizeof(char *));
	if (!argv)
		return (NULL);
	if (ft_init_argv(argv, ac, av) < 0)
		return (NULL);
	return (argv);
}

int	ft_init_here_doc(char *file, char *eof)
{
	int		fd;
	char	*line;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		ft_err3_open(errno, file);
	line = get_next_line(IN);
	while (line)
	{
		if (ft_strlen(line) > 1 && strncmp(line, eof, ft_strlen(line) - 1) == 0)
		{
			free(line);
			break ;
		}
		if (write(fd, line, ft_strlen(line)) < 0)
			ft_err7_write(errno, file);
		free(line);
		line = get_next_line(IN);
	}
	close(fd);
	return (0);
}
