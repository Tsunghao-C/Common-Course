/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:16:24 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/13 10:24:05 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char *av[]) {

	int	i;
	int	j;

	if (ac < 1)
		return (0);
	else if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 0;
	while (++i < ac && av) {
		j = -1;
		while (av[i] && av[i][++j]) {
			std::cout << (char)std::toupper(av[i][j]);
		}
	}
	std::cout << std::endl;
	return (0);
}
