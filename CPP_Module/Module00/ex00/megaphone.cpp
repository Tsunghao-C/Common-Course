/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:16:24 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/11 14:40:06 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	get_uppercase(char c) {

	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	output(char *str) {

	char	c;

	while (*str)
	{
		c = get_uppercase(*str);
		std::cout << c;
		str++;
	}
}

int	main(int ac, char *av[]) {

	int	i;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < ac)
		output(av[i++]);
	std::cout << std::endl;
	return (0);
}
