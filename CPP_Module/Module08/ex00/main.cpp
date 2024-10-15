/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:47:22 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/15 14:52:51 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int		main() {
	std::cout << "--------- test on int list --------- " << std::endl;
	std::list<int>	int_list;
	int_list.push_back(42);
	int_list.push_back(77);
	int_list.push_back(8);
	int_list.push_back(39);
	int_list.push_back(-7);
	int_list.push_back(39);
	
	try
	{
		int  first_found = ::easyfind(int_list, -7);
		std::cout << first_found << std::endl;
		::easyfind(int_list, 99);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "--------- test on string vector --------- " << std::endl;
	std::vector<std::string> str_vector;
	str_vector.push_back("Hello world!");
	str_vector.push_back("Bonjour le monde!");
	str_vector.push_back("Guten tag");
	str_vector.push_back("Selamat Bagi");

	try
	{
		std::string	str_found = ::easyfind(str_vector, "Guten tag");
		std::cout << str_found << std::endl;
		::easyfind(str_vector, "Guten morgan");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;	
}