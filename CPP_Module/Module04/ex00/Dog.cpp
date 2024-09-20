/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:58:30 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 15:44:26 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	this->_type = "Dog";
	std::cout << "A Dog object is created by default constructor" << std::endl;
}

Dog::Dog(const Dog& other) {
	std::cout << "A Dog object is copied" << std::endl;
	*this = other;
}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "A Dog object is destroyed" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Bark bark~~~~" << std::endl;
}