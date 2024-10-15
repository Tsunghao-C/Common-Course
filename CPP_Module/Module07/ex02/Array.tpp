/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:34:05 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/15 13:26:26 by tsuchen          ###   ########.fr       */
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
Array<T>::Array() : _arr_size(0), _array(new T[_arr_size]()) {
	// std::cout << "Default con is called" << std::endl;
}

template < typename T >
Array<T>::Array(unsigned int n) : _arr_size(n), _array(new T[_arr_size]()) {
	// std::cout << "number con is called" << std::endl;
}

template < typename T >
Array<T>::Array(Array const &other) : _arr_size(0), _array(new T[_arr_size]()) {
	// std::cout << "copy con called " << this->_array << " " << other._array << std::endl;
	*this = other;
}

template < typename T >
Array<T>& Array<T>::operator=(Array<T> const &other) {
	// std::cout << "copy assignment called " << this->_array  << " " << other._array << std::endl;
	if (this != &other) {
		delete[] this->_array;
		this->_arr_size = other._arr_size;
		this->_array = new T[this->_arr_size]();
		for (unsigned int i = 0; i < this->_arr_size; i++) {
			this->_array[i] = other._array[i];
		}
	}
	return *this;
}

template < typename T >
Array<T>::~Array() {
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

template < typename T >
std::ostream & operator<<(std::ostream &o, Array<T> const &rhs) {
	for (unsigned int i = 0; i < rhs.size(); i++) {
		o << "array " << i << " is: " << rhs[i] << std::endl;
	}
	return o;
}