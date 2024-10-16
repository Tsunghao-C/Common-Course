/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:23:17 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/16 17:22:16 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int		main() {
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() <<std::endl;

	try
	{
		sp.addNumber(6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span	sp2 = Span(10);
	try
	{sp2.longestSpan();}
	catch(const std::exception& e)
	{ std::cerr << e.what() << '\n';}
	try
	{sp2.shortestSpan();}
	catch(const std::exception& e)
	{ std::cerr << e.what() << '\n';}
	sp2.addNumber(1);
	try
	{sp2.longestSpan();}
	catch(const std::exception& e)
	{ std::cerr << e.what() << '\n';}
	Span	sp3 = Span(10000);
	sp3.fillNumbers(10000);
	std::cout << "numberadde" << std::endl;
	// sp3.printAll();
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;
	return 0;
}