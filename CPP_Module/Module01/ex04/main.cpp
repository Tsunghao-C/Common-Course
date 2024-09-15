/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:11:57 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/13 20:18:29 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int ac, char *av[]) {
	
	if (ac != 4 || !av || !av[1] || !av[2] || !av[3]) {
		std::cout << "Wrong input arguments" << std::endl;
		return EXIT_FAILURE;
	}
	std::ifstream	ifs(av[1], std::ifstream::in);
	if (ifs.fail()) {
		std::cerr << "Error: Failed to open file " << av[1] << std::endl;
		return EXIT_FAILURE;
	}
	std::string		outfile = av[1];
	std::string		buff;
	std::ofstream	ofs(outfile.append(".replace"), std::ofstream::out | std::ofstream::trunc);
	if (ofs.fail()) {
		std::cerr << "Error: Failed to open file " << outfile << std::endl;
		ifs.close();
		return EXIT_FAILURE;
	}
	while (!ifs.eof()) {
		std::getline(ifs, buff);
		sed(ofs, av[2], av[3], buff);
	}
	ifs.close();
	ofs.close();
	return EXIT_SUCCESS;
}