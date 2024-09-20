/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:58:30 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 18:54:14 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _brain(new Brain) {
	this->_type = "Dog";
	std::cout << "A Dog object is created by default constructor" << std::endl;
}

Dog::Dog(const Dog& other) : _brain(new Brain) {
	std::cout << "A Dog object is copied" << std::endl;
	*this = other;
}
// Since _brain is a pointer, we need to create a new Brain in the initialize
// list to create an "Unique brain" for this copy object

Dog&	Dog::operator=(const Dog& other) {
	std::cout << "Assignment Dog called" << std::endl;
	if (this != &other) {
		*this->_brain = *other._brain;
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "A Dog object is destroyed" << std::endl;
	delete _brain;
}

void	Dog::makeSound() const {
	std::cout << "Bark bark~~~~" << std::endl;
}

void	Dog::createIdea(std::string const &str) {
	std::cout << "Dog way thinking, adding " << str << " in brain" << std::endl;
	this->_brain->setIdea(str);
}

std::string const	&Dog::getIdea(unsigned int i) const {
	return this->_brain->getIdea(i);
}