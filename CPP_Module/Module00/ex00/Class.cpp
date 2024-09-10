/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:11:56 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/10 17:01:32 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample_class.hpp"

int	main(void) {

	//Initialize using initialization list
	Sample	Initiator( 42, 'a', 4.02f);

	//Initiator.bar();
	Initiator.foo = 24;
	//Initiator.noo = 4.2f;		//This is not compile-able because "noo" is const
	//Initiator._foo = 2424;	//This is not compile-able because "_foo" is private 
	//Initiator._bar();		//This is not compile-able because "_bar" is private
	std::cout << "Initiator.foo in main: [" << Initiator.foo << "]" << std::endl;
	/* Accessors */
	std::cout << "Use getFoo to access _foo: " << Initiator.getFoo() << std::endl;
	Initiator.setFoo(2424);
	std::cout << "Use setFoo to change _foo to 2424: " << Initiator.getFoo() << std::endl;
	Initiator.setFoo(-2424);
	std::cout << "Use setFoo to change _foo to -2424: " << Initiator.getFoo() << std::endl;
	return 0;
}
