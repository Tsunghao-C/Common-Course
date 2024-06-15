/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:10:47 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/09 20:20:40 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <string.h>
int	main(int ac, char *av[])
{
	if (ac != 2 || strlen(av[1]) != 1)
		return (0);
	ft_putchar_fd(*(av[1]), 1);
	return (0);
}*/
