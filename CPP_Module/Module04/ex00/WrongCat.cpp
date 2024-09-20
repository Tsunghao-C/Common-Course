/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:58:30 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 16:49:59 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->_type = "WrongCat";
	std::cout << "A WrongCat object is created by default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
	std::cout << "A WrongCat object is copied" << std::endl;
	*this = other;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "A WrongCat object is destroyed" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "Meow meow~~~~" << std::endl;
}