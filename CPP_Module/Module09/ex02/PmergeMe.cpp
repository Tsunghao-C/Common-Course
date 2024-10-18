/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:22:07 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/18 22:26:47 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> const &input) : _c_vec(input) {
	for (std::vector<int>::const_iterator it = input.begin(); it != input.end(); ++it) {
		_c_deque.push_back(*it);
	}
}

PmergeMe::PmergeMe(PmergeMe const &other) { *this = other; }

PmergeMe& PmergeMe::operator=(PmergeMe const &other) {
	if (this != &other) {
		this->_c_vec = other._c_vec;
		this->_c_deque = other._c_deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::sort_compare() {
	std::cout << "Before: " << _c_vec << std::endl;
	// do vector sort
	clock_t	vec_start = clock();
	merge_sort(_c_vec.begin(), _c_vec.end());
	clock_t	vec_end = clock();

	// do list sort
	clock_t	deque_start = clock();
	merge_sort(_c_deque.begin(), _c_deque.end());
	clock_t deque_end = clock();
	std::cout << "After:  " << _c_vec << std::endl;
	std::cout << "Time to process a range of " << _c_vec.size() << " elements with std::[vector] : ";
	std::cout << std::fixed << std::setprecision(5) << static_cast<double>(vec_end - vec_start) / CLOCKS_PER_SEC << " us" << std::endl;
	std::cout << "Time to process a range of " << _c_deque.size() << " elements with std::[deque] : ";
	std::cout << std::fixed << std::setprecision(5) << static_cast<double>(deque_end - deque_start) / CLOCKS_PER_SEC << " us" << std::endl;
}

bool	PmergeMe::isPositiveNum(std::string argv) {
	std::string::iterator	it;
	for (it = argv.begin(); it != argv.end(); ++it) {
		if (!isdigit(*it)) {
			return false;
		}
	}
	return true;
}

std::ostream & operator<<(std::ostream &o, std::vector<int> const &rhs) {
	for (std::vector<int>::const_iterator it = rhs.begin(); it != rhs.end(); ++it) {
		o << " " << *it;	
	}
	return o;
}

template < typename Iter >
void	merge_sort(Iter first, Iter last) {
	// if only one element, do nothing
	if (last - first > 1) {
		// find middle point
		Iter middle = first + (last - first) / 2;
		// recursively split to left and right
		merge_sort(first, middle);
		merge_sort(middle, last);
		// merge in order back
		std::inplace_merge(first, middle, last);
	}
}