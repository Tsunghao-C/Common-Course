/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:30:01 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/23 18:26:14 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name) {
	std::cout << "A character object [" << name << "] is created by default constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inv[i] = 0;
	}
}

Character::Character(const Character& other) {
	std::cout << "A character is copied from " << other._name << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inv[i] = 0;
	}
	// We still need to initialize in the Copy Constructor. It won't call the 
	// Default constructor here!
	*this = other;
}

Character&  Character::operator=(const Character& other) {
	if (this != &other) {
		ICharacter::operator=(other);
		this->_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (this->_inv[i]) {
				delete this->_inv[i];
			}	// delete the original materias if there is any
			if (other._inv[i]) {
				this->_inv[i] = other._inv[i]->clone();
			}	// clone a new materia if there is any
		}
	}
	return *this;
}

Character::~Character() {
	std::cout << "A character is destroyed" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_inv[i]) {
			delete this->_inv[i];
		}
	}
}

std::string const   &Character::getName() const {
	return this->_name;
}

void    Character::equip(AMateria *m) {
	for (int idx = 0; idx < 4; idx++) {
		if (!this->_inv[idx]) {
			this->_inv[idx] = m;
			std::cout << "Character " << _name << " equipped " << m->getType() << " at #" << idx << std::endl;
			return ;
		}
	}
	std::cout << "Cannot equip. The Material slot full!" << std::endl;
}

void    Character::unequip(int idx) {
	if (idx > 3 || idx < 0) {
		std::cout << "invalid index number!" << std::endl;
		return ;
	}
	if (!this->_inv[idx]) {
		std::cout << "Cannot unequip. The slot is empty!" << std::endl;
		return ;
	}
	this->_inv[idx] = 0;
	std::cout << "Character " << _name << " unquipped materia #" << idx << std::endl;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx > 3 || idx < 0) {
		std::cout << "invalid index number!" << std::endl;
		return ;
	}
	if (!this->_inv[idx]) {
		std::cout << "Cannot use Materia. The slot is empty!" << std::endl;
		return ;
	}
	this->_inv[idx]->use(target);
}