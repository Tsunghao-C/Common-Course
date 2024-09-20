/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:58:30 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 15:44:29 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->_type = "Cat";
	std::cout << "A Cat object is created by default constructor" << std::endl;
}

Cat::Cat(const Cat& other) {
	std::cout << "A Cat object is copied" << std::endl;
	*this = other;
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "A Cat object is destroyed" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow meow~~~~" << std::endl;
}