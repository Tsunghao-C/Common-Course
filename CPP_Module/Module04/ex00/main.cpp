/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:38:33 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 16:53:08 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main() {
	
	const	Animal*	meta = new Animal();
	const	Animal*	i = new Cat();
	const	Animal*	j = new Dog();

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << "-----------Wrong Animal Check-------------" << std::endl;
	const	WrongAnimal*	k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	delete meta;
	delete i;
	delete j;
	delete k;
	return 0;
}