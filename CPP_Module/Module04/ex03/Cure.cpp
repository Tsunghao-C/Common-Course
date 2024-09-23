/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:51:28 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/23 13:16:25 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "An Cure object is created by default constructor" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria("cure") {
	std::cout << "An Cure object is copied" << std::endl;
	*this = other;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Cure::~Cure() {
	std::cout << "An Cure object is destroyed" << std::endl;
}

Cure*	Cure::clone() const {
	std::cout << "An Cure object is cloned" << std::endl;
	return new Cure(*this);
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
