/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:44:31 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/16 13:01:42 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
	this->setName("");
	std::cout << "A nameless Zombie class created." << std::endl;
}

Zombie::Zombie(const std::string& name) : _name(name) {
	std::cout << this->_name << " from Zombie class created." << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << this->_name << " from Zombie class destroyed." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}