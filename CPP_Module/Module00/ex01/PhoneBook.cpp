/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:34:57 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/12 15:42:50 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook (void) {

	std::cout << "PhoneBook Constructed!" << std::endl;
	this->_num_contacts = 0;
}

PhoneBook::~PhoneBook (void) {

	std::cout << "PhoneBook Deconstructed!" << std::endl;
}

int	PhoneBook::getNumContacts(void) {

	return (this->_num_contacts);
}
