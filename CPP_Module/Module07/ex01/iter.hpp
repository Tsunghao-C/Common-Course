/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:11:12 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/12 21:41:39 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

template < typename T >
void	iter(T arr[], int arr_size, void (f)(T &)) {
	for (int i = 0; i < arr_size; i++) {
		f(arr[i]);
	}
}

template < typename T >
void	triple(T & arr_item) {
	arr_item = 3 * arr_item;
}

template < typename T >
void	printAll(T & arr_item) {
	std::cout << std::fixed << std::setprecision(2) << arr_item << std::endl;
}