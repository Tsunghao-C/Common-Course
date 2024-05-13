/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:20:59 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/09 20:29:10 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, &(*(s++)), 1);
	write(fd, "\n", 1);
}
/*
int	main(int ac, char *av[])
{
	if (ac != 2)
		return (0);
	ft_putendl_fd(av[1], 1);
	return (0);
}*/
