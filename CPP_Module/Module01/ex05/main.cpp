/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:47:02 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/16 11:00:10 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char *av[]) {

	if (ac != 2 || !av || !av[1]) {
		std::cout << "Incorrect Input" << std::endl;
		return EXIT_FAILURE;
	}
	Harl	c1;
	c1.complain(av[1]);
	return EXIT_SUCCESS;
}