/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:05:59 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/13 16:48:02 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {

	// Zombie	king("King");
	Zombie	king;
	Zombie*	queen;

	king.setName("King");
	king.announce();
	std::cout << "Below objects are allocated in heap. They should be dead when calling delete:" << std::endl;
	queen = newZombie("Queen");
	queen->announce();
	// Declear widow as a reference. It will always reference to widow. Cannot point to others
	Zombie&	widow = *newZombie("Widow");
	widow.announce();
	std::cout << "Following objects are created in stack. They should die immediately:" << std::endl;
	randomChump("Solder 1");
	randomChump("Servant 1");
	std::cout << "Calling delete to allocated Queen and Widow:" << std::endl;
	delete queen;
	delete &widow;
	std::cout << "Finally, the King is destroyed by destructor when exitng main:" << std::endl;
	return (0);
}
