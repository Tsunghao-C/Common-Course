/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:53:03 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/30 21:39:08 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str_rd;
	int		nu_rd;
	char		buff[BUFFER_SIZE];
	char		*tmp;
	char		*opt;

	if (fd == -1)
		return (NULL);
	str_rd = NULL;
	if (!str_rd)
	{
		nu_rd = read(fd, buff, BUFFER_SIZE);
		if (nu_rd == -1)
			return (NULL);
		str_rd = (char *)malloc((nu_rd + 1) * sizeof(char));
		if (!str_rd)
			return (NULL);
		ft_strlcpy(str_rd, buff, nu_rd + 1);
	}
	tmp = ft_strchr(str_rd, '\n');		// find the first '\n' in str_rd
	if (tmp)				//create substring and return
	{
		opt = ft_substr(str_rd, 0, tmp - str_rd + 1);
		str_rd = tmp + 1;
	}
	else					// read more!
	{
		d
	}
	return (opt);
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
	printf("1st call :%s", get_next_line(fd));
	printf("2nd call :%s", get_next_line(fd));
	close(fd);
	return (0);
}
