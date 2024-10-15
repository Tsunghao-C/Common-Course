/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:22:08 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/15 11:32:17 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int     main() {
	std::cout << "-------------------- Test with INT ---------------------------" << std::endl;
	int		int_arr[5] = { 1, 2, 3, 4, 5 };
	iter<int>(int_arr, 5, printAll<int>);
	iter<int>(int_arr, 5, triple<int>);
	iter<int>(int_arr, 5, printAll<int>);
	iter<int>(int_arr, 5, printIncrement<int>);

	std::cout << "-------------------- Test with const INT ---------------------------" << std::endl;
	int	const	int_arr_c[5] = { 6, 7, 8, 9, 10 };
	iter<int>(int_arr_c, 5, printAll_c<int>);

	std::cout << "-------------------- Test with Float ---------------------------" << std::endl;
	float	float_arr[6] = { 0.1, 0.2, 0.3, 1.4, 2, -1 };
	iter<float>(float_arr, 6, printAll<float>);
	iter<float>(float_arr, 6, triple<float>);
	iter<float>(float_arr, 6, printAll<float>);

	std::cout << "-------------------- Test with char ---------------------------" << std::endl;
	char	char_arr[3] = { '!', '&', '#' };
	iter<char>(char_arr, 3, printAll<char>);
	iter<char>(char_arr, 3, triple<char>);
	iter<char>(char_arr, 3, printAll<char>);
	
	std::cout << "-------------------- Test with string ---------------------------" << std::endl;
	std::string		str[2] = { "Hello world!", "This is C++ Module 07" };
	iter<std::string>(str, 2, printAll<std::string>);
	
	std::cout << "-------------------- Test with const string ---------------------------" << std::endl;
	std::string	const	str_c[2] = { "Hello world!", "This is C++ Module 07" };
	iter<std::string>(str_c, 2, printAll_c<std::string>);
	return 0;
}