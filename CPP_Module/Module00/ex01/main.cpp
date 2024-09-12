/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:47:44 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/12 16:07:21 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {

	std::string buff;
	PhoneBook	my_phone_book;

	std::cout << "Enter a command: ";
	while (std::getline(std::cin, buff)) {

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
		std::cout << "Enter a command: ";
	}
	if (std::cin.eof()) {
		std::cout << std::endl << "EOF detected. Exiting program." << std::endl;
	}
	return (0);
}
