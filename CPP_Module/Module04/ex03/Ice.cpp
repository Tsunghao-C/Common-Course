/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:51:28 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/23 13:16:34 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "An Ice object is created by default constructor" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria("ice") {
	std::cout << "An Ice object is copied" << std::endl;
	*this = other;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice() {
	std::cout << "An Ice object is destroyed" << std::endl;
}

Ice*	Ice::clone() const {
	std::cout << "An Ice object is cloned" << std::endl;
	return new Ice(*this);
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
