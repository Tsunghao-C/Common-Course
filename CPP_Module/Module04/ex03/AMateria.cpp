/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:46:32 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/23 14:00:11 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {
	std::cout << "A AMateria of type [" << _type << "] is created by default constructor" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	std::cout << "A AMateria is copied" << std::endl;
	*this = other;
}

AMateria&	AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

AMateria::~AMateria() {
	std::cout << "A AMatera is destroyed" << std::endl;
}

std::string const	&AMateria::getType() const {
	return this->_type;
}

void	AMateria::use(ICharacter &target) {
	std::cout << "Use Materia to " << target.getName() << " in Materia class" << std::endl;
}