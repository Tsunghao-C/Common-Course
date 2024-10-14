/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:34:05 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/14 14:33:04 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template < typename T >
class Array<T>::OutOfRangeException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Out of range in this array!!!";
	}
};

template < typename T >
Array<T>::Array() : _arr_size(0) {
	this->_array = NULL;	
}

template < typename T >
Array<T>::Array(unsigned int n) : _arr_size(n) {
	if (n == 0)
		this->_array = NULL;
	else
		this->_array = new T[n];
}

template < typename T >
Array<T>::Array(Array const &other) {
	*this = other;
}

template < typename T >
Array<T>& Array<T>::operator=(Array<T> const &other) {
	if (this != &other) {
		this->_arr_size = other._arr_size;
		if (this->_arr_size == 0) {
			this->_array = NULL;
		} else {
			this->_array = new T[_arr_size];
			for (unsigned int i = 0; i < this->_arr_size; i++) {
				this->_array[i] = other._array[i];
			}
		}
	}
	return *this;
}

template < typename T >
Array<T>::~Array() {
	if (this->_array != NULL)
		delete[] this->_array;
}

template < typename T >
T&	Array<T>::operator[](unsigned int index) {
	if (index >= this->_arr_size)
		throw Array<T>::OutOfRangeException();
	return this->_array[index];
}

template < typename T >
const T&	Array<T>::operator[](unsigned int index) const {
	if (index >= this->_arr_size)
		throw Array<T>::OutOfRangeException();
	return this->_array[index];
}

template < typename T >
unsigned int	Array<T>::size() const {
	return this->_arr_size;
};