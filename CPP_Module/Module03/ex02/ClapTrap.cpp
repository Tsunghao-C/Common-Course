/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:25:55 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/19 01:18:51 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Name("No name"), _HP(CL_HP), _ENG(CL_ENG), _ATK(CL_ATK) {
	std::cout << "A ClapTrap object " << this->_Name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _Name(name), _HP(CL_HP), _ENG(CL_ENG), _ATK(CL_ATK) {
	std::cout << "A ClapTrap object " << this->_Name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
	std::cout << "A ClapTrap object is copied from " << other._Name << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "[CL] assignment operater is called!" << std::endl;
	if (this != &other) {
		this->_Name = other._Name;
		this->_HP = other._HP;
		this->_ENG = other._ENG;
		this->_ATK = other._ATK;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "A ClapTrap object " << this->_Name << " is destroyed!" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (!this->_HP) {
		std::cout << this->_Name << " cannot attack. Dead already!" << std::endl;
		return ;
	}
	if (!this->_ENG) {
		std::cout << this->_Name << " cannot attack. No energy!" << std::endl;
		return ;
	}
	this->_ENG--;
	
	std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing ";
	std::cout << this->_ATK << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!this->_HP) {
		std::cout << this->_Name << " cannot take damage. Dead already!" << std::endl;
		return ;
	}
	unsigned int	i = 0;
	while (i < amount && this->_HP > 0) {
		this->_HP--;
		i++;
	}
	if (!this->_HP) {
		std::cout << this->_Name << " takes " << i << " damages and die!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_Name << " takes " << amount << " of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->_HP) {
		std::cout << this->_Name << " cannot heal. Dead already!" << std::endl;
		return ;
	}
	if (!this->_ENG) {
		std::cout << this->_Name << " cannot heal. No energy!" << std::endl;
		return ;
	}
	this->_ENG--;
	unsigned int	i = 0;
	while (i < amount && this->_HP < this->_getMaxHP()) {
		this->_HP++;
		i++;
	}
	std::cout << "ClapTrap " << this->_Name << " heals by " << i << " points!" << std::endl;
}

std::string const	&ClapTrap::getName(void) const {
	return this->_Name;
}

unsigned int	ClapTrap::getHP(void) const {
	return this->_HP;
}

unsigned int	ClapTrap::getENG(void) const {
	return this->_ENG;
}

unsigned int	ClapTrap::getATK(void) const {
	return this->_ATK;
}

unsigned int	ClapTrap::_getMaxHP() const {
	return CL_HP;
}