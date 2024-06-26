/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:41:35 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/26 18:22:25 by tsuchen          ###   ########.fr       */
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
/*
int	ft_init_fdout(int *fd_out, int ac, char **av)
{
	if (!strcmp(av[1], "here_doc"))
		*fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		*fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (*fd_out == -1)
	{
		ft_err3_open(errno, av[ac - 1]);
		close(IN);
		return (-1);
	}
	return (0);
}*/

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
	return (i);
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
	j = i;
	if (fd_in == -1)
		i++;
	else
	{
		dup2(fd_in, IN);
		close(fd_in);
	}
	dup2(fd_out, OUT);
	close(fd_out);
	while (i < ac - 2)
		ft_do_pipe(av[i++], env);
	ft_do_fork_main(av[i], env);
	while (j < ac - 1)
	{
		wait(NULL);
		j++;
	}
	if (!ft_strcmp(av[1], "here_doc"))
		unlink(av[1]);
	return (0);
}
