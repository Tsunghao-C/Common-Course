/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:37:16 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/18 14:45:13 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	a("Tim");
	ClapTrap	b("Cook");
	ClapTrap	c(b);
	ClapTrap	d;

	d = a;	//Timmy is now Tim as well

	a.attack(b.getName());
	b.takeDamage(a.getATK());
	b.beRepaired(3);

	std::cout << "-------------------------------------------" << std::endl;
	b.attack(d.getName());
	d.takeDamage(5);
	d.beRepaired(1);
	d.beRepaired(1);
	d.beRepaired(1);
	d.beRepaired(1);
	std::cout << "should only heal 1 point below: " << std::endl;
	d.beRepaired(2);
	std::cout << "-------------------------------------------" << std::endl;
	d.attack(c.getName());
	d.attack(c.getName());
	d.attack(c.getName());
	d.attack(c.getName());
	d.attack(c.getName());
	std::cout << "should not be able to attack below: " << std::endl;
	d.attack(c.getName());
	std::cout << "-------------------------------------------" << std::endl;
	c.takeDamage(3);
	c.takeDamage(2);
	c.takeDamage(4);
	std::cout << "should only take 1 damage and die: " << std::endl;
	c.takeDamage(5);
	std::cout << "should not be able to take damage: " << std::endl;
	c.takeDamage(2);
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "should not be able to heal: " << std::endl;
	c.beRepaired(4);
	return 0;
}