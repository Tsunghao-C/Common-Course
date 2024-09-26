/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:53:10 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/26 11:52:30 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	
	try
	{
		Bureaucrat  bob("Bob");
		bob.decrement();
		std::cout << bob << std::endl;
		bob.increment();
		std::cout << bob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat  tom("Tom", 2);
		tom.increment();
		std::cout << tom << std::endl;
		tom.increment();
		std::cout << tom << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Tom Error: " << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat  cook("Cook", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Cook Error: " << e.what() << '\n';
	}
	try
	{
		Bureaucrat  nobody("Nobody", 150);
		std::cout << nobody << std::endl;
		nobody.decrement();
		std::cout << nobody << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Nobody Error: " << e.what() << '\n';
	}
}