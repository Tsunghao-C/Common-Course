/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:53:03 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/02 20:55:19 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_list		*bgn_lst;
	char		*next_line;

	if (fd == -1 || read(fd, &next_line, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!bgn_lst || ft_have_nl_lst(bgn_lst) == 0)
		ft_fetch_nl(fd, &bgn_lst);	//read fd and generate str_lst until '\n' found
	//printf("lst 1:%p, %s\n", bgn_lst, bgn_lst->str);
	//printf("lst 2:%p, %s\n", bgn_lst->next, bgn_lst->next->str);
	next_line = ft_gen_nl(&bgn_lst);
	ft_update_list(&bgn_lst);
	return (next_line);
}

#include <stdio.h>

int	main(int ac, char *av[])
{
	int	fd;

	if (ac == 1)
		fd = STDIN_FILENO;
	else if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		return (0);
	int	i = 1;
	//char	*line;

	//line = get_next_line(fd);
	/*
	while (line)
	{
		printf("%d call :%s", i, line);
		line = get_next_line(fd);
		i++;
	}*/
	while (i++ < 30)
	{
		printf("%d call :%s", i, get_next_line(fd));
	}
	//printf("1st call :%s", get_next_line(fd));
	//printf("2nd call :%s", get_next_line(fd));
	close(fd);
	return (0);
}
