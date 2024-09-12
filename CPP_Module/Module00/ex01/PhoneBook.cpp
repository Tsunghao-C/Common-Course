/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:34:57 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/12 20:35:44 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {

	// std::cout << "PhoneBook Constructed!" << std::endl;
	this->_index = 0;
}

PhoneBook::~PhoneBook(void) {

	// std::cout << "PhoneBook Deconstructed!" << std::endl;
}

void PhoneBook::addContact(void) {

	int			i;
	std::string	str;

	str = "";
	if (this->_index > 7)
		std::cout << "Warning: Over maximum capacity! Will overwrite previous data." << std::endl;
	i = this->_index % 8;
	while (!std::cin.eof() && str == "") {
		std::cout << "Enter First_Name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[i].set_fname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "") {
		std::cout << "Enter Last_Name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[i].set_lname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "") {
		std::cout << "Enter Nick_Name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[i].set_nick(str);
	}
	str = "";
	while (!std::cin.eof() && str == "") {
		std::cout << "Enter Phone_Number: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[i].set_phone(str);
	}
	str = "";
	while (!std::cin.eof() && str == "") {
		std::cout << "Enter Darkest_Secret: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[i].set_secret(str);
	}
	if (std::cin.eof())
		std::cout << std::endl << "Exit ADD due to EOF" << std::endl;
	else
		std::cout << "Contact " << i + 1 << " is added successfully!" << std::endl;
	this->_index++;
}

void	PhoneBook::searchContact(void) const{

	std::string	input;
	int			index;

	// identify valid index input
	while (true) {
		std::cout << "Enter the index of a contact: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << std::endl << "Exit SEARCH due to EOF!" << std::endl;
			return ;
		}
		std::stringstream ss(input);
		if (ss >> index && ss.eof() && (index > 0 && index < 9))
			break ;
		std::cout << "Invalid index. Try again!" << std::endl;
	}
	// print searched contact
	std::cout << "First_Name    : " << this->_contacts[index - 1].get_fname() << std::endl;
	std::cout << "Last_Name     : " << this->_contacts[index - 1].get_lname() << std::endl;
	std::cout << "Nick_Name     : " << this->_contacts[index - 1].get_nick() << std::endl;
	std::cout << "Phone_Number  : " << this->_contacts[index - 1].get_phone() << std::endl;
	std::cout << "Darkest_Secret: " << this->_contacts[index - 1].get_secret() << std::endl;
}

static	std::string fixed_size(std::string str, u_int32_t max) {
	
	if (str.length() > max) {
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

void	PhoneBook::printContact(void) const {

	int		i;

	i = 0;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|Index     |F_Name    |L_Name    |N_Name    |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (i < this->_index && i < 8) {
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << fixed_size(this->_contacts[i].get_fname(), 10);
		std::cout << "|" << std::setw(10) << fixed_size(this->_contacts[i].get_lname(), 10);
		std::cout << "|" << std::setw(10) << fixed_size(this->_contacts[i].get_nick(), 10);
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}