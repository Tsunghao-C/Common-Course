/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:38:33 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/22 13:35:20 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main() {
	
	// const	AAnimal*	meta = new AAnimal();
	const	AAnimal*	i = new Cat();
	const	AAnimal*	j = new Dog();

	Dog*	d = new Dog();
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	// meta->makeSound();
	std::cout << "-------------Set Ideas to Brain--------------" << std::endl;
	d->createIdea("What's a Dog?");
	d->createIdea("What's a Cat?");
	d->createIdea("Am I a Dog?");
	std::cout << "Idea 1: [" << d->getIdea(0) << "] in Dog's brain" << std::endl;
	std::cout << "Idea 2: [" << d->getIdea(1) << "] in Dog's brain" << std::endl;
	std::cout << "Idea 3: [" << d->getIdea(2) << "] in Dog's brain" << std::endl;
	std::cout << "Idea 4: [" << d->getIdea(3) << "] in Dog's brain" << std::endl;
	std::cout << "-------------Check Copy of Brain--------------" << std::endl;
	Dog	e(*d);
	// e = *d;
	std::cout << "Idea 1: [" << e.getIdea(0) << "] in Copy Dog's brain" << std::endl;
	std::cout << "Idea 2: [" << e.getIdea(1) << "] in Copy Dog's brain" << std::endl;
	std::cout << "Idea 3: [" << e.getIdea(2) << "] in Copy Dog's brain" << std::endl;
	std::cout << "Idea 4: [" << e.getIdea(3) << "] in Copy Dog's brain" << std::endl;

	std::cout << "-------------Check Copy2 of Brain--------------" << std::endl;
	Dog	*f = new Dog();
	*f = *d;
	std::cout << "Idea 1: [" << f->getIdea(0) << "] in Copy2 Dog's brain" << std::endl;
	std::cout << "Idea 2: [" << f->getIdea(1) << "] in Copy2 Dog's brain" << std::endl;
	std::cout << "Idea 3: [" << f->getIdea(2) << "] in Copy2 Dog's brain" << std::endl;
	std::cout << "Idea 4: [" << f->getIdea(3) << "] in Copy2 Dog's brain" << std::endl;
	
	// delete meta;
	delete i;
	delete j;
	delete d;
	delete f;
	std::cout << "--------------Array of Animals------------------" << std::endl;
	AAnimal		*herd[4];
	herd[0] = new Dog();
	herd[1] = new Dog();
	herd[2] = new Cat();
	herd[3] = new Cat();

	std::cout << "----------delete the array of animals-----------" << std::endl;
	for (int z = 0; z < 4; z++) {
		delete herd[z];
	}
	return 0;
}