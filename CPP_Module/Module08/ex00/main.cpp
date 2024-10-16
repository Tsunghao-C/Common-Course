/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:47:22 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/16 15:28:03 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>

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
		std::list<int>::iterator first_found = ::easyfind(int_list, 39);
		std::cout << "first found(39): " << *first_found << std::endl;
		std::cout << "next item(-7): " << *(++first_found) << std::endl;
		::easyfind(int_list, 99);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "--------- test on int vector --------- " << std::endl;
	std::vector<int> int_vector;
	int_vector.push_back(99);
	int_vector.push_back(88);
	int_vector.push_back(77);
	int_vector.push_back(88);
	int_vector.push_back(99);

	try
	{
		std::vector<int>::iterator	int_found = ::easyfind(int_vector, 88);
		std::cout << "first found(88): " << *int_found << std::endl;
		std::cout << "next item(77): " << *(++int_found) << std::endl;
		::easyfind(int_vector, 66);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;	
}