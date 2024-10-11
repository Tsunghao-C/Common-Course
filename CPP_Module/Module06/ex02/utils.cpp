/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:03:43 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/11 12:27:46 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

Base *  generate(void) {
	Base    *ptr;
	srand(static_cast<unsigned int>(time(0)));
	if (rand() % 3 == 0) {
		// generate A
		ptr = new A();
	} else if (rand() % 3 == 1) {
		// generate B
		ptr = new B();
	} else {
		// generate C
		ptr = new C();
	}
	return ptr;
}

void    identify(Base * p) {
	A   *A_ptr = dynamic_cast<A *>(p);
	if (A_ptr != NULL) {
		A_ptr->announce();
	}
	B	*B_ptr = dynamic_cast<B *>(p);
	if (B_ptr != NULL) {
		B_ptr->announce();
	}
	C	*C_ptr = dynamic_cast<C *>(p);
	if (C_ptr != NULL) {
		C_ptr->announce();
	}
}

void    identify(Base & p) {
	try
	{
		A	&A_ref = dynamic_cast<A &>(p);
		A_ref.announce();
	}
	catch(const std::exception& e) {}
	try
	{
		B	&B_ref = dynamic_cast<B &>(p);
		B_ref.announce();
	}
	catch(const std::exception& e) {}
	try
	{
		C	&C_ref = dynamic_cast<C &>(p);
		C_ref.announce();
	}
	catch(const std::exception& e) {}
}