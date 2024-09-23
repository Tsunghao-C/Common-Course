/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:17:28 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/23 14:04:02 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main() {
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter	*me = new Character("me");

	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter	*bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "--------------delete character without equipment---------------" << std::endl;
	delete bob;
	std::cout << "--------------delete character equipped with Materia---------------" << std::endl;
	delete me;
	std::cout << "--------------delete the MateriaSource---------------" << std::endl;
	delete src;

	return 0;	
}