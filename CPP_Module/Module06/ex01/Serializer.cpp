/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:00:34 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/11 11:06:51 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &other) {(void)other;}

Serializer& Serializer::operator=(Serializer const &other) {
    (void)other;
    return *this;
}

Serializer::~Serializer() {}

uintptr_t   Serializer::serialize(Data * ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *  Serializer::deserialize(uintptr_t raw) {
    Data    *ptr = reinterpret_cast<Data *>(raw);
    return ptr;
}