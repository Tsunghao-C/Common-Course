/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:22:51 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/14 15:04:25 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>
# include <sstream>

template < typename T >
class Array
{
private:
	/* data */
	T	*_array;
	unsigned int	_arr_size;
public:
	Array();
	Array(unsigned int n);
	Array(Array const &other);
	Array&	operator=(Array const &other);
	T&	operator[](unsigned int index);
	const T&	operator[](unsigned int index) const;
	~Array();
public:
	unsigned int	size() const;
public:
	class OutOfRangeException;
};

template < typename T >
std::ostream &	operator<<(std::ostream &o, Array<T> const &rhs);

# include "Array.tpp"

#endif