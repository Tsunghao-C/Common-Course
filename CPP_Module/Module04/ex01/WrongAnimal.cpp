/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:37:26 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 16:47:14 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal_type") {
	std::cout << "A WrongAnimal object is created by default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "A WrongAnimal object is copied" << std::endl;
	*this = other;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "A WrongAnimal object is destroyed!" << std::endl;
}

std::string const	&WrongAnimal::getType(void) const {
	return this->_type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "Gggggggg...." << std::endl;
}