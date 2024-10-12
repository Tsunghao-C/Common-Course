/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templateSample.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:33:01 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/12 21:05:27 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>


template <typename T>
void	swap( T &a, T &b) {
	T	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	const & max( T const &a, T const &b) {
	return a > b ? a : b;
}

template <typename T>
T	const & min( T const &a, T const &b) {
	return a < b ? a : b;
}