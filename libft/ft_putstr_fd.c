/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:12:32 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/09 20:17:23 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, &(*(s++)), 1);	
}
/*
int	main(int ac, char *av[])
{
	if (ac != 2)
		return (0);
	ft_putstr_fd(av[1], 1);
	return (0);
}*/
