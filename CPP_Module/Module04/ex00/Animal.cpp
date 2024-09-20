/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:37:26 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 15:44:53 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal_type") {
	std::cout << "An Animal object is created by default constructor" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "An Animal object is copied" << std::endl;
	*this = other;
}

Animal&	Animal::operator=(const Animal& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "An Animal object is destroyed!" << std::endl;
}

std::string const	&Animal::getType(void) const {
	return this->_type;
}

void	Animal::makeSound() const {
	std::cout << "Zzzzz...." << std::endl;
}