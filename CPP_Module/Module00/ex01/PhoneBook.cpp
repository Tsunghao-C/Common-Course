/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:34:57 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/11 19:59:38 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

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
