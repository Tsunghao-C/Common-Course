/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:14:49 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/18 11:20:10 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int		main(int ac, char *av[]) {
	if (ac != 2) {
		std::cerr << "Error: Incorrect input." << std::endl;
		return 1;
	}
	try
	{
		RPN		rpn(static_cast<std::string>(av[1]));
		double	result = rpn.do_rpn_cal();
		std::cout << std::fixed << std::setprecision(2) << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<  "Error: " << e.what() << '\n';
	}
	return 0;
}