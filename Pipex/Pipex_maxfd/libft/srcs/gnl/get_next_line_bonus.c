/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:53:03 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/15 13:57:55 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list_gnl	*bgn_lst[MAX_FD];
	char				*next_line;

	if (fd == -1 || read(fd, &next_line, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (fd >= 0 && bgn_lst[fd])
		{
			ft_delone(bgn_lst[fd]);
			bgn_lst[fd] = NULL;
		}
		return (NULL);
	}
	if (!bgn_lst[fd] || ft_have_nl_lst(bgn_lst[fd]) == 0)
		ft_fetch_nl(fd, &bgn_lst[fd]);
	next_line = ft_gen_nl(bgn_lst[fd]);
	if (bgn_lst[fd])
		ft_update_list(&bgn_lst[fd]);
	if (!next_line && bgn_lst[fd])
	{
		ft_delone(bgn_lst[fd]);
		bgn_lst[fd] = NULL;
	}
	return (next_line);
}

int	ft_have_nl_lst(t_list_gnl *bgn_lst)
{
	t_list_gnl	*tmp;
	char		*tmp2;

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

void	ft_fetch_nl(int fd, t_list_gnl **bgn_lst)
{
	int		nu_rd;
	char	*buff;

	while (!ft_have_nl_lst(*bgn_lst))
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return ;
		nu_rd = read(fd, buff, BUFFER_SIZE);
		if (!nu_rd || nu_rd == -1)
		{
			free(buff);
			return ;
		}
		buff[nu_rd] = '\0';
		ft_lst_append(bgn_lst, buff);
	}
}

char	*ft_gen_nl(t_list_gnl *lst)
{
	char	*next_line;
	char	*tmp2;
	int		i;

	if (ft_line_size(lst) == 0)
		return (NULL);
	next_line = (char *)malloc((ft_line_size(lst) + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	i = 0;
	while (lst)
	{
		tmp2 = lst->str;
		while (*tmp2 && *tmp2 != '\n')
			next_line[i++] = *tmp2++;
		if (*tmp2 == '\n')
		{
			next_line[i++] = '\n';
			break ;
		}
		lst = lst->next;
	}
	next_line[i] = '\0';
	return (next_line);
}

void	ft_update_list(t_list_gnl **lst)
{
	t_list_gnl	*tmp;
	char		*str_left;
	char		*tmp2;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while ((*lst)->next)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_delone(tmp);
	}
	tmp2 = (*lst)->str;
	while (*tmp2 && *tmp2 != '\n')
		tmp2++;
	if (*tmp2 == '\n')
		tmp2++;
	str_left = ft_strdup(tmp2);
	ft_delone(*lst);
	*lst = NULL;
	if (str_left && *str_left != '\0')
		ft_lst_append(lst, str_left);
	else
		free(str_left);
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
