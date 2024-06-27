/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:41:35 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/27 15:25:42 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_init_here_doc(char *file, char *eof)
{
	int		fd;
	char	*limiter;
	char	*line;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return (-1);
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
	int	i;

	if (!strcmp(av[1], "here_doc"))
	{
		*fd_in = ft_init_here_doc(av[1], av[2]);
		*fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		i = 3;
	}
	else
	{
		*fd_in = open(av[1], O_RDONLY);
		*fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		i = 2;
	}
	if (*fd_in == -1)
		ft_err3_open(errno, av[1]);
	if (*fd_out == -1)
		ft_err3_open(errno, av[ac - 1]);
	return (i);
}

static void	ft_false_io(int *start, int mode)
{
	int	fd[2];

	if (pipe(fd) == -1)
		ft_err2_pipe(errno);
	if (mode == 0)
	{
		ft_dup_close(fd[0], IN);
		close(fd[1]);
		*start += 1;
	}
	else
	{
		ft_dup_close(fd[1], OUT);
		close(fd[0]);
	}
}

static void	ft_check_fdio(int fd_in, int fd_out, int *start)
{
	if (fd_in == -1)
		ft_false_io(start, 0);
	else
		ft_dup_close(fd_in, IN);
	if (fd_out == -1)
		ft_false_io(start, 1);
	else
		ft_dup_close(fd_out, OUT);
}

int	main(int ac, char *av[], char **env)
{
	int	fd_in;
	int	fd_out;
	int	i;
	int	j;

	if (ac < 5 || (!strcmp(av[1], "here_doc") && ac < 6))
		ft_err1_argc(ac);
	i = ft_init_fdio(&fd_in, &fd_out, ac, av);
	ft_check_fdio(fd_in, fd_out, &i);
	j = i;
	while (i < ac - 2)
		ft_do_pipe(av[i++], env);
	ft_do_fork_main(av[i], env);
	while (j++ < ac - 1)
		wait(NULL);
	if (!ft_strcmp(av[1], "here_doc"))
		unlink(av[1]);
	return (0);
}
