/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:50:43 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/23 14:09:25 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "A MateriaSource is create by default constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inv[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << "A MateriaSource is copied" << std::endl;
	*this = other;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		IMateriaSource::operator=(other);
		// handle the base (abstract) class assignment first
		for (int i = 0; i < 4; i++) {
			if (this->_inv[i]) {
				delete this->_inv[i];
			}
			if (other._inv[i]) {
				this->_inv[i] = other._inv[i]->clone();
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "A MateriaSource is destroyed" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_inv[i]) {
			delete this->_inv[i];
		}
	}
}

void	MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!this->_inv[i]) {
			this->_inv[i] = m;
			std::cout << "Learned a materia " << m->getType() << " at index #" << i << std::endl;
			return ;
		}
	}
	std::cout << "Cannot learn a Materia. Slots are full!" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->_inv[i]->getType() == type) {
			return _inv[i]->clone();
		}
	}
	std::cout << "Cannot find a learned materia!" << std::endl;
	return 0;
}
