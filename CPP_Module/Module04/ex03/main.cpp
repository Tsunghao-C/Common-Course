/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:17:28 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/23 14:59:04 by tsuchen          ###   ########.fr       */
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
	std::cout << "--------------trying to add more Materia Sources---------------" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria	*tmp2;
	tmp2 = new Ice();
	std::cout << "!!!! should not be able to learn more  !!!!" << std::endl;
	src->learnMateria(tmp2);
	delete tmp2;
	std::cout << "--------------trying to equip more Materia---------------" << std::endl;
	std::cout << "!!!! should fail to create New Matera copy  !!!!" << std::endl;
	tmp2 = src->createMateria("none");
	tmp2 = src->createMateria("ice");
    me->equip(tmp2);
    tmp2 = src->createMateria("ice");
	me->equip(tmp2);
	tmp2 = src->createMateria("cure");
	std::cout << "!!!! should fail to equip !!!!" << std::endl;
	me->equip(tmp2);
	delete tmp2;
	std::cout << "--------------trying to unequip more Materia #1---------------" << std::endl;
	me->unequip(1);
	std::cout << "!!!! should fail to use Cure anymore !!!!" << std::endl;
	me->use(1, *bob);
	delete tmp;
	std::cout << "--------------check copy of Characters---------------" << std::endl;
	Character	tim("Tim");
	tim.equip(src->createMateria("ice"));
	tim.equip(src->createMateria("cure"));
	tim.use(1, *bob);
	Character	cook(tim);
	cook.use(1, *me);


	std::cout << "--------------delete character without equipment---------------" << std::endl;
	delete bob;
	std::cout << "--------------delete character equipped with Materia---------------" << std::endl;
	delete me;
	std::cout << "--------------delete the MateriaSource---------------" << std::endl;
	delete src;
	std::cout << "--------------delete stack object Tim and Cook---------------" << std::endl;

	return 0;	
}