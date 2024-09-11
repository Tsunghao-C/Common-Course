/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:47:44 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/11 19:59:34 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

int	main(void) {

	std::string buff;
	PhoneBook	my_phone_book;

	while (true) {

		std::cout << "Enter a command: ";
		if (!std::getline (std::cin, buff)) {

			if (std::cin.eof()) {
				std::cout << std::endl << "EOF detected. Exiting program." << std::endl;
			}
			else {
				std::cout << "Input error. Exiting program." << std::endl;
			}
			break ;
		}
		std::cout << buff << std::endl;
		if (buff == "EXIT")
			break ;
		else if (buff == "ADD") {
			std::cout << std::setw(10) << 12345 << std::endl;
			// Add contact;
		}
		else if (buff == "SEARCH") {
			std::cout << std::setw(10) << 12345678 << std::endl;
			// Search contact;
		}
	}
	return (0);
}
