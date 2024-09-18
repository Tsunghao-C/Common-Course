/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:37:16 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/19 01:08:05 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void) {

	FragTrap	a("Tim");
	a.highFivesGuys();
	
	DiamondTrap	d("Steve");
	
	d.attack(a.getName());
	d.takeDamage(23);
	d.beRepaired(30);
	d.whoAmI();
	
	std::cout << "HP: " << d.getHP() << std::endl;
	std::cout << "ENG: " << d.getENG() << std::endl;
	std::cout << "ATK: " << d.getATK() << std::endl;	
	return 0;
}