/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:20:08 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/17 11:37:41 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int		main(int ac, char *av[]) {
	if (ac != 2) {
		std::cerr << "Error: incorrect input number." << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange::do_conversion(static_cast<std::string>(av[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}
	return 0;
}