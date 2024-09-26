/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:53:10 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/26 18:09:12 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	
	try
	{
		Bureaucrat  tom("Tom", 20);
		Form	doc1("Doc_1", 20, 30);
		std::cout << doc1 << std::endl;
		Form	doc2("Doc_2", 2, 30);
		std::cout << tom << std::endl;
		tom.signForm(doc1);
		std::cout << doc1 << std::endl;
		tom.increment();
		std::cout << tom << std::endl;
		tom.signForm(doc2);
		tom.signForm(doc1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Tom Error: " << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat  cook("Cook");
		Form	doc3("Doc3", -1, 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Doc3 Error: " << e.what() << '\n';
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