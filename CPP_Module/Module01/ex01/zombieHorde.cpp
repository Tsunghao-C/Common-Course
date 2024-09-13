/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:55:05 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/13 17:15:35 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {

	int		i;

	if (N < 1) {
		std::cerr << "Error: N must be non-zero positive integer" << std::endl;
		return (nullptr);
	}
	Zombie	*horde = new Zombie[N];
	if (!horde) {
		std::cerr << "Memory alloc failed" << std::endl;
		return (nullptr);
	}
	i = 0;
	while (i < N)
		horde[i++].setName(name);
	return (horde);
}
