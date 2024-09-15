/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:11:57 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/15 18:18:40 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int ac, char *av[]) {
	
	if (ac != 4 || !av || !av[1] || !av[2] || !av[3] || !strlen(av[2])) {
		std::cerr << "Wrong input arguments" << std::endl;
		return EXIT_FAILURE;
	}
	Sed	sed1(av[1], av[2], av[3]);
	if (sed1.SedReplacer())
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}