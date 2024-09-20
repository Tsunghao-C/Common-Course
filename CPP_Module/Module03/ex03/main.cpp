/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:37:16 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 11:16:33 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void) {

	FragTrap	a("Tim");
	a.highFivesGuys();
	
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Name_Base: " << a.getName() << std::endl;
	std::cout << "HP: " << a.getHP() << std::endl;
	std::cout << "ENG: " << a.getENG() << std::endl;
	std::cout << "ATK: " << a.getATK() << std::endl;	
	std::cout << "Max HP: " << a._getMaxHP() << std::endl;
	std::cout << "------------------------------------" << std::endl;
	
	DiamondTrap	d("Steve");
	
	DiamondTrap	*e = new DiamondTrap("Jobs");
	FragTrap	*f = e;
	DiamondTrap	*g = new DiamondTrap("Apple");
	ScavTrap	*h = g;
	
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Name: " << d.getNewName() << std::endl;
	std::cout << "Name_Base: " << d.getName() << std::endl;
	std::cout << "HP: " << d.getHP() << std::endl;
	std::cout << "ENG: " << d.getENG() << std::endl;
	std::cout << "ATK: " << d.getATK() << std::endl;	
	std::cout << "Max HP: " << d._getMaxHP() << std::endl;
	std::cout << "------------------------------------" << std::endl;
	
	d.attack(a.getName());
	d.takeDamage(23);
	d.beRepaired(30);
	d.highFivesGuys();
	d.guardGate();
	d.guardGate();
	d.whoAmI();
	std::cout << "------------------------------------" << std::endl;
	
	std::cout << "Name: " << d.getNewName() << std::endl;
	std::cout << "Name_Base: " << d.getName() << std::endl;
	std::cout << "HP: " << d.getHP() << std::endl;
	std::cout << "ENG: " << d.getENG() << std::endl;
	std::cout << "ATK: " << d.getATK() << std::endl;	
	
	std::cout << "------------------------------------" << std::endl;
	std::cout << "To call destructor on ClapTrap on purpose" << std::endl;
	delete f;
	std::cout << "------------------------------------" << std::endl;
	delete h;
	std::cout << "------------------------------------" << std::endl;
	
	return 0;
}