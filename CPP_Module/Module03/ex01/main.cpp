/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:37:16 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 10:19:10 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap	t;
	ScavTrap	a("Tim");
	ScavTrap	b("Cook");
	ScavTrap	c(b);
	ScavTrap	d("Timmy");

	ScavTrap*	e = new ScavTrap(d);
	ClapTrap*	f = e;

	d = a;	//Timmy is now Tim as well

	a.attack(b.getName());
	b.takeDamage(a.getATK());
	b.beRepaired(13);

	std::cout << "-------------------------------------------" << std::endl;
	b.attack(d.getName());
	d.takeDamage(b.getATK());
	d.beRepaired(10);
	d.beRepaired(5);
	d.beRepaired(3);
	d.beRepaired(1);
	std::cout << "should only heal 1 point below: " << std::endl;
	d.beRepaired(20);
	std::cout << "-------------------------------------------" << std::endl;
	d.attack(c.getName());
	d.attack(c.getName());
	d.attack(c.getName());
	d.attack(c.getName());
	d.attack(c.getName());
	d.attack(c.getName());
	std::cout << "-------------------------------------------" << std::endl;
	c.takeDamage(d.getATK());
	c.takeDamage(d.getATK());
	c.takeDamage(d.getATK());
	c.takeDamage(d.getATK());
	std::cout << "should only take 20 damages and die: " << std::endl;
	c.takeDamage(d.getATK());
	std::cout << "should not be able to take damage: " << std::endl;
	c.takeDamage(d.getATK());
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "should not be able to heal: " << std::endl;
	c.beRepaired(10);
	a.guardGate();
	a.guardGate();
	c.guardGate();
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "Call the destructor from base class on purpose" << std::endl;	
	delete f;
	std::cout << "-------------------------------------------" << std::endl;
	return 0;
}