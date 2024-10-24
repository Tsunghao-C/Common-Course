/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:08:30 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/18 21:20:52 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int		main(int ac, char *av[]) {
	if (ac < 2) {
		std::cerr << "Error: insufficient input." << std::endl;
		return 1;
	}
	std::vector<int>	args;
	for (int i = 1; i < ac; i++) {
		if (!PmergeMe::isPositiveNum(av[i])) {
			std::cerr << "Error: invalid input. Only accept positive int!" << std::endl;
			return 1;
		}
		args.push_back(std::atoi(av[i]));
	}
	PmergeMe	merge_data(args);
	merge_data.sort_compare();
	return 0;
}