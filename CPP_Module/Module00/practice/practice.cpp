/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:30:59 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/10 14:11:36 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Class and Objects */


/* STDIN STDOUT Stream */
/*
#include <iostream>

int	main(void){

	char	buff[512];

	std::cout << "Hello world !" << std::endl;
	// << is redirect the following string into STDOUT stream.
	std::cin >> buff;
	// >> is redirect the STDIN into buff
	std::cout << "You entered: [" << buff << "]" << std::endl;
	// std is the class name (or namespace) in the iostream library
	// cin, cout, cerr, clog are the objects for narrow characters (char)
	// wcin, wcout, wcerr, wclog are objects for wide characters (wchar_t)
	return 0;
}*/

/* Namespace */
/*
#include <stdio.h>

int	g1_var = 1;
int	f(void) {return 2;};

namespace	Foo {
	int	g1_var = 3;
	int	f(void) {return 4;};

}

namespace	Bar = Foo;

int	main(void){
	printf("g1_var:		[%d]\n", g1_var);
	printf("f():		[%d]\n\n", f());

	printf("Foo::g1_var:	[%d]\n", Foo::g1_var);
	printf("Foo::f():	[%d]\n\n", Foo::f());

	printf("Bar::g1_var:	[%d]\n", Bar::g1_var);
	printf("Bar::f():	[%d]\n\n", Bar::f());
	return (0);
}*/
