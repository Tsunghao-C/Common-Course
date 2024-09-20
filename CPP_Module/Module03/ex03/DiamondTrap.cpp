/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:55:02 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 11:19:17 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _Name("No name") {
	ClapTrap::_Name = this->_Name + "_clap_name";
	this->_ENG = SC_ENG;
	// The _HP and _ATK are override by the last inherited class FragTrap, so 
	// I only need to assign again the values not is not from FragTrap.
	std::cout << "A DiamondTrap object " << this->_Name << " is created by default constructor!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), _Name(name) {
	this->_ENG = SC_ENG;
	std::cout << "A DiamondTrap object " << this->_Name << " is created by name constructor!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
	std::cout << "A DiamondTrap object is copied from " << other.getName() << std::endl;
	*this = other;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout<< "[DI] assignment operator is called!" << std::endl;
	if (this != &other) {
		this->_Name = other._Name;
		ClapTrap::operator=(other);
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "A DiamondTrap object " << this->_Name << " is destroyed!" << std::endl;
}

unsigned int	DiamondTrap::_getMaxHP() const {
	return 120;
}

std::string const	&DiamondTrap::getNewName(void) const {
	return this->_Name;
}

void	DiamondTrap::whoAmI() {
	std::cout << "I am a diamond object " << this->_Name << ", I was once known as " << ClapTrap::_Name << std::endl;
}
