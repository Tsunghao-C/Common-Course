/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:33:38 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/11 11:44:39 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main() {
	Data	*ptr = new Data();
	Data	*ptr2 = new Data('#', 78, 94.78f, "LOL", ptr);

	uintptr_t	ser_raw = Serializer::serialize(ptr);
	uintptr_t	ser_raw2 = Serializer::serialize(ptr2);

	std::cout << " *********** Serialization Complete *********** " << std::endl;
	std::cout << "raw 1: " << ser_raw << std::endl;
	std::cout << "raw_2: " << ser_raw2 << std::endl;
	
	Data	*deser_ptr = Serializer::deserialize(ser_raw);
	Data	*deser_ptr2 = Serializer::deserialize(ser_raw2);
	
	std::cout << "\n *********** Deserialization Complete *********** " << std::endl;
	std::cout << " ---- First pair before ---- " << std::endl;
	ptr->printData();
	std::cout << " ---- First pair after ----" << std::endl;
	deser_ptr->printData();
	std::cout << " ---- Second pair before ---- " << std::endl;
	ptr2->printData();
	std::cout << " ---- Second pair after ---- " << std::endl;
	deser_ptr2->printData();
	delete deser_ptr;
	delete deser_ptr2;
	return 0;
}