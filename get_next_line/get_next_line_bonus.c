/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:53:03 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/04 15:35:13 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}

void	ft_delone(t_list *lst)
{
	free(lst->str);
	free(lst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (siz > 0)
	{
		while ((i < (siz - 1)) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

int	ft_have_nl_lst(t_list *bgn_lst)
{
	t_list	*tmp;
	char	*tmp2;

	tmp = bgn_lst;
	while (tmp)
	{
		tmp2 = tmp->str;
		while (*tmp2)
		{
			if (*tmp2 == '\n')
				return (1);
			tmp2++;
		}
		tmp = tmp->next;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*bgn_lst;
	char			*next_line;

	if (fd == -1 || read(fd, &next_line, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (bgn_lst)
		{
			ft_delone(bgn_lst);
			bgn_lst = NULL;
		}
		return (NULL);
	}
	if (!bgn_lst || ft_have_nl_lst(bgn_lst) == 0)
		ft_fetch_nl(fd, &bgn_lst);
	next_line = ft_gen_nl(bgn_lst);
	if (bgn_lst)
		ft_update_list(&bgn_lst);
	if (!next_line && bgn_lst)
	{
		ft_delone(bgn_lst);
		bgn_lst = NULL;
	}
	return (next_line);
}
/*
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
	int	i = 0;
	char	*line;

	line = get_next_line(fd);
	
	while (line)
	{
		i++;
		printf("%.3d call :%s", i, line);
		free(line);
		line = get_next_line(fd);
	}
	//printf("1st call\n%s", get_next_line(fd));
	//printf("2nd call\n%s", get_next_line(fd));
	close(fd);
	return (0);
}*/
