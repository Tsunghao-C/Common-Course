/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:11:56 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/13 14:18:22 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample_class.hpp"


void	f1(int Sample::*foo_p, void (Sample::*bar_p)(void) const) {

	Sample Initiator2( 24, 'b', 4.4f);
	std::cout << "The number of instances is: " << Sample::getNumIns() << std::endl;
	Initiator2.*foo_p = 6;	//Using instance variable dereference value to member ptr foo_p
	std::cout << "Initiator.foo in main: [" << Initiator2.foo << "]" << std::endl;
	(Initiator2.*bar_p)();
}


int	main(void) {


	//std::cout << "The number of instances is: " << Sample::getNumIns() << std::endl;
	//Initialize using initialization list
	Sample	Initiator( 42, 'a', 4.02f);
	Sample	*Init_p = &Initiator;

	// You can create a class pointer that points to an attribute in a class. It can be used 
	// across all instances.
	int	Sample::*foo_p = &Sample::foo;			//ptr to an int in the class structure
	void	(Sample::*bar_p)(void) const = &Sample::bar;	//ptr to a f in the class structure
	
	/* Reference */
	int	num = 42;
	int	*num_ptr = &num;
	int	&num_ref = num;		//reference is a dereferenced constant ptr that always point to sth.
	
	std::cout << num << " " << *num_ptr << " " << num_ref << std::endl;

	*num_ptr = 21;
	num_ref = 84;			//change number with reference
	std::cout << num << " " << *num_ptr << " " << num_ref << std::endl;


	std::cout << "The number of instances is: " << Sample::getNumIns() << std::endl;
	f1(foo_p, bar_p);
	std::cout << "The number of instances is: " << Sample::getNumIns() << std::endl;
	//Initiator.bar();
	Initiator.foo = 1;	//Using instance variable to assign value to member foo
	std::cout << "Initiator.foo in main: [" << Initiator.foo << "]" << std::endl;
	(*Init_p).foo = 2;	//Using instance pointer to assign value to member foo
	std::cout << "Initiator.foo in main: [" << Initiator.foo << "]" << std::endl;
	Initiator.*foo_p = 3;	//Using instance variable dereference value to member ptr foo_p
	std::cout << "Initiator.foo in main: [" << Initiator.foo << "]" << std::endl;
	Init_p->*foo_p = 4;	//Using instance pointer to dereference value to member ptr foo_p
	std::cout << "Initiator.foo in main: [" << Initiator.foo << "]" << std::endl;
	(*Init_p).*foo_p = 5;	//Using instance pointer to  dereference value to member ptr foo_p
	std::cout << "Initiator.foo in main: [" << Initiator.foo << "]" << std::endl;
	
	Initiator.bar();	//Using instance variable to call member function bar (method)
	(Initiator.*bar_p)();	//Using instance variable to call member fuction with member ptr
	(*Init_p).bar();	//Using instance pointer to call method
	((*Init_p).*bar_p)();	//Using instance pointer to call method with member ptr
	(Init_p->*bar_p)();	//Using instance pointer to call method with member ptr directly
	//Initiator.noo = 4.2f;		//This is not compile-able because "noo" is const
	//Initiator._foo = 2424;	//This is not compile-able because "_foo" is private 
	//Initiator._bar();		//This is not compile-able because "_bar" is private
	std::cout << "Initiator.foo in main: [" << Initiator.foo << "]" << std::endl;
	/* Accessors */
	/*
	std::cout << "Use getFoo to access _foo: " << Initiator.getFoo() << std::endl;
	Initiator.setFoo(2424);
	std::cout << "Use setFoo to change _foo to 2424: " << Initiator.getFoo() << std::endl;
	Initiator.setFoo(-2424);
	std::cout << "Use setFoo to change _foo to -2424: " << Initiator.getFoo() << std::endl;
	return 0;
	*/
}
