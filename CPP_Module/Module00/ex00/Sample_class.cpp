/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample_class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:53:38 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/10 17:01:36 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample_class.hpp"

//What we did inside constructor is to initialization. It it possible to initialize
//a "const" variable. 

Sample::Sample(int p1, char p2, float const p3) : foo(p1), coo(p2), noo(p3) {

        std::cout << "Constructor called!" << std::endl;

        //this->foo = 42;
        //"this" is a pointer on the current instance
        std::cout << "this->foo " << this->foo << std::endl;
	//Use initialization list after constructor
	std::cout << "this->coo " << this->coo << std::endl;
	std::cout << "this->noo " << this->noo << std::endl;
        this->bar();
	this->_foo = 4242;
	std::cout << "this->_foo " << this->_foo << std::endl;
	this->_bar();

        return ;

}

Sample::~Sample(void){

        std::cout << "Deconstructor called!" << std::endl;
        return ;

}

void    Sample::bar(void) const {

        std::cout << "Member public function bar called!" << std::endl;
}

void	Sample::_bar(void) const {

	std::cout << "Member private function bar called!" << std::endl;
}

int	Sample::getFoo(void) const {

	return this->_foo;
	std::cout << "In getFoo" << std::endl;
}

void	Sample::setFoo(int value) {

	if (value >= 0)
		this->_foo = value;
	std::cout << "In setFoo" << std::endl;
	return ;
}
