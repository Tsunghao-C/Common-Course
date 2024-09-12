/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:47:44 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/12 19:30:59 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {

	std::string buff;
	PhoneBook	my_phone_book;

	std::cout << "Welcome to My_Phone_Book!" << std::endl;
	while (!std::cin.eof()) {
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, buff)) {
			std::cout << std::endl;
			break ;
		}
		if (buff == "EXIT")
			break ;
		else if (buff == "ADD") {
			// Add contact;
			my_phone_book.addContact();
		}
		else if (buff == "SEARCH") {
			// print all contacts in summary mode
			my_phone_book.printContact();
			// Search contact;
			my_phone_book.searchContact();
		}
	}
	if (std::cin.eof())
		std::cout << "EOF detected. Exiting program." << std::endl;
	else
		std::cout << "Bye~~~~~" << std::endl;
	return (0);
}
