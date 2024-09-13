/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:05:59 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/13 11:41:07 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {

	Zombie	king = Zombie("King");
	Zombie*	queen;
	Zombie* widow;

	king.announce();
	std::cout << "Here are the class pointers, they should be dead when calling delete:" << std::endl;
	queen = queen->newZombie("Queen");
	queen->announce();
	widow = king.newZombie("Widow");
	widow->announce();
	std::cout << "Following objects are called from member function, they should die immediately:" << std::endl;
	king.randomChump("Solder 1");
	queen->randomChump("Servant 1");
	std::cout << "Calling delete to kill class pointers Queen and Widow:" << std::endl;
	delete queen;
	delete widow;
	std::cout << "Finally, the King is destroyed by decontructor when exitng main:" << std::endl;
	return (0);
}
