/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:58 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/13 19:02:28 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon & w) : _name(name), _weapon_a(w) {
    std::cout << "HumanA " << this->_name << " is created with weapon " << this->_weapon_a.getType() << std::endl;
}

HumanA::~HumanA(void) {
    std::cout << "HumanA " << this->_name << " is destroyed" << std::endl;
}

void    HumanA::attack(void) {
    std::cout << this->_name << " attacks with their " << this->_weapon_a.getType() << std::endl;
}

void    HumanA::setWeapon(Weapon w) {
    this->_weapon_a = w;
}