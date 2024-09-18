/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:55:02 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/19 01:22:48 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _Name("No name") {
	// this->_Name = "No name";
	ClapTrap::_Name = this->_Name + "_clap_name";
	this->_HP = FragTrap::getHP();
	this->_ENG = ScavTrap::getENG();
	this->_ATK = FragTrap::getATK();
	std::cout << "A DiamondTrap object " << this->_Name << " is created!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : _Name(name) {
	// this->_Name = name;
	ClapTrap::_Name = _Name + "_clap_name";
	this->_HP = FragTrap::getHP();
	this->_ENG = ScavTrap::getENG();
	this->_ATK = FragTrap::getATK();
	std::cout << "A DiamondTrap object " << this->_Name << " is created!" << std::endl;
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
	return FR_HP;
}

void	DiamondTrap::whoAmI() {
	std::cout << "I am a diamond object " << this->_Name << ", I was once known as " << ClapTrap::_Name << std::endl;
}
