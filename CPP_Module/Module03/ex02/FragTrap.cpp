/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:55:02 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/19 01:18:25 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->_Name = "No name";
	this->_HP = FR_HP;
	this->_ENG = FR_ENG;
	this->_ATK = FR_ATK;
	std::cout << "A FragTrap object " << this->getName() << " is created!" << std::endl;
}

FragTrap::FragTrap(const std::string &name) {
	this->_Name = name;
	this->_HP = FR_HP;
	this->_ENG = FR_ENG;
	this->_ATK = FR_ATK;
	std::cout << "A FragTrap object " << this->getName() << " is created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
	std::cout << "A FragTrap object is copied from " << other.getName() << std::endl;
	*this = other;
}

FragTrap&	FragTrap::operator=(const FragTrap &other) {
	std::cout<< "[FR] assignment operator is called!" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "A FragTrap object " << this->getName() << " is destroyed!" << std::endl;
}

void	FragTrap::attack(const std::string &target) {
	if (!this->_HP) {
		std::cout << "[FR] " << this->_Name << " cannot attack. Dead already!" << std::endl;
		return ;
	}
	if (!this->_ENG) {
		std::cout << "[FR] " << this->_Name << " cannot attack. No energy!" << std::endl;
		return ;
	}
	this->_ENG--;
	
	std::cout << "[FR] " << this->_Name << " attacks " << target << ", causing ";
	std::cout << this->_ATK << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
		std::cout << "[FR] " << this->getName() << " displays a positive high five request!" << std::endl;
}

unsigned int	FragTrap::_getMaxHP() const {
	return FR_HP;
}
