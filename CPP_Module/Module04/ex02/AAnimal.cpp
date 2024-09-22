/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:37:26 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/22 13:04:34 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Animal_type") {
	std::cout << "An AAnimal object is created by default constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
	std::cout << "An Animal object is copied" << std::endl;
	*this = other;
}

AAnimal&	AAnimal::operator=(const AAnimal& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "An Animal object is destroyed!" << std::endl;
}

std::string const	&AAnimal::getType(void) const {
	return this->_type;
}

void	AAnimal::makeSound() const {
	std::cout << "Zzzzz...." << std::endl;
}