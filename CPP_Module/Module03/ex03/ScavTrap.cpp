/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:55:02 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/19 16:32:03 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _isGuarded(0)  {
	this->_Name = "No name";
	this->_HP = SC_HP;
	this->_ENG = SC_ENG;
	this->_ATK = SC_ATK;
	std::cout << "A ScavTrap object " << this->getName() << " is created by default constructor!" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : _isGuarded(0) {
	this->_Name = name;
	this->_HP = SC_HP;
	this->_ENG = SC_ENG;
	this->_ATK = SC_ATK;
	std::cout << "A ScavTrap object " << this->getName() << " is created by name constructor!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
	std::cout << "A ScavTrap object is copied from " << other.getName() << std::endl;
	*this = other;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other) {
	std::cout<< "[SC] assignment operator is called!" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		this->_isGuarded = other._isGuarded;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "A ScavTrap object " << this->getName() << " is destroyed!" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (!this->_HP) {
		std::cout << "[SC] " << this->_Name << " cannot attack. Dead already!" << std::endl;
		return ;
	}
	if (!this->_ENG) {
		std::cout << "[SC] " << this->_Name << " cannot attack. No energy!" << std::endl;
		return ;
	}
	this->_ENG--;
	
	std::cout << "[SC] " << this->_Name << " attacks " << target << ", causing ";
	std::cout << this->_ATK << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate() {
	if (!this->_isGuarded) {
		std::cout << "[SC] " << this->getName() << " is now in Gate keeper mode!" << std::endl;
		this->_isGuarded = 1;
	}
	else {
		std::cout << "[SC] " << this->getName() << " finish Gate keeper mode!" << std::endl;
		this->_isGuarded = 0;
	}
}

unsigned int	ScavTrap::_getMaxHP() const {
	return SC_HP;
}
