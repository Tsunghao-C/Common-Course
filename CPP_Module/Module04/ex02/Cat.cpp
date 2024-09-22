/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:58:30 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/22 13:12:40 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : _brain(new Brain) {
	this->_type = "Cat";
	std::cout << "A Cat object is created by default constructor" << std::endl;
}

Cat::Cat(const Cat& other) : _brain(new Brain) {
	std::cout << "A Cat object is copied" << std::endl;
	*this = other;
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		*this->_brain = *other._brain;
		AAnimal::operator=(other);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "A Cat object is destroyed" << std::endl;
	delete _brain;
}

void	Cat::makeSound() const {
	std::cout << "Meow meow~~~~" << std::endl;
}

void	Cat::createIdea(std::string const &str) {
	std::cout << "Dog way thinking, adding " << str << " in brain" << std::endl;
	this->_brain->setIdea(str);
}

std::string const	&Cat::getIdea(unsigned int i) const {
	return this->_brain->getIdea(i);
}