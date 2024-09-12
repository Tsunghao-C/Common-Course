/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:02:10 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/12 19:00:46 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	
	// std::cout << "Contact Constructed!" << std::endl;
}

Contact::~Contact(void) {
	
	// std::cout << "Contact Deconstructed!" << std::endl;
}

std::string Contact::get_fname(void) const {

	return this->_fname;
}

std::string Contact::get_lname(void) const {

	return this->_lname;
}

std::string Contact::get_nick(void) const {

	return this->_nick;
}

std::string Contact::get_phone(void) const {

	return this->_phone;
}

std::string Contact::get_secret(void) const {

	return this->_secret;
}

void	Contact::set_fname(std::string str) {

	this->_fname = str;
}

void	Contact::set_lname(std::string str) {

	this->_lname = str;
}

void	Contact::set_nick(std::string str) {

	this->_nick = str;
}

void	Contact::set_phone(std::string str) {

	this->_phone = str;
}

void	Contact::set_secret(std::string str) {

	this->_secret = str;
}
