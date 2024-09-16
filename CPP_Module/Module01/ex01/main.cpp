/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:05:59 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/16 13:04:18 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {

	Zombie		king = Zombie("King");
	Zombie*		pawns;
	int	const	num_pawns = 10;
	int			i;

	king.announce();
	king.setName("King Junior");
	king.announce();
	pawns = zombieHorde(num_pawns, "Soldier");
	if (!pawns) {
		std::cerr << "Failed to create zombie horde" << std::endl;
		return 1;
	}
	i = 0;
	while (i < num_pawns)
		pawns[i++].announce();
	delete[] pawns;
	return 0;
}
