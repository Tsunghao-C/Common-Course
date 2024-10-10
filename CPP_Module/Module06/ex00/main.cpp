/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:49:33 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/10 11:52:13 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int		main(int ac, char *av[])
{
	if (ac == 2) {
		ScalarConverter::convert(av[1]);
		return 0;
	}
	return 1;
}