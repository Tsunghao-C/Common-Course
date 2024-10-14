/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:54:13 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/14 15:57:11 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
private:
	/* data */
public:
	Serializer();
	Serializer(Serializer const &other);
	Serializer&	operator=(Serializer const &other);
	~Serializer();

	static uintptr_t	serialize(Data *ptr);
	static Data *	deserialize(uintptr_t raw);
	
};
