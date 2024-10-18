/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:22:07 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/18 23:40:26 by tsuchen          ###   ########.fr       */
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
	merge_sort2(_c_vec, _c_vec.begin(), _c_vec.end());
	// merge_sort(_c_vec.begin(), _c_vec.end());
	clock_t	vec_end = clock();

	// do list sort
	clock_t	deque_start = clock();
	merge_sort2(_c_deque, _c_deque.begin(), _c_deque.end());
	// merge_sort(_c_deque.begin(), _c_deque.end());
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

template < typename Container >
void	merge(Container &cont, typename Container::iterator first, typename Container::iterator middle, typename Container::iterator last) {
	typedef	typename Container::iterator	c_it;
	(void)cont;
	
	Container	tmp(last - first);
	c_it	left = first;
	c_it	right = middle;
	c_it	tmp_it = tmp.begin();

	// sorting and copy to tmp
	while (left < middle && right < last) {
		if (*left <= *right) {
			*tmp_it = *left;
			++left;
		} else {
			*tmp_it = *right;
			++right;
		}
		++tmp_it;
	}
	// copying the remaining, could be left or right
	while (left < middle) {
		*tmp_it = *left;
		++left;
		++tmp_it;
	}
	while (right < last) {
		*tmp_it = *right;
		++right;
		++tmp_it;
	}
	// overwrite sorted tmp to original container
	std::copy(tmp.begin(), tmp.end(), first);
}

template < typename Container >
void	merge_sort2(Container &cont, typename Container::iterator first, typename Container::iterator last) {
	if (last - first > 1) {
		// find middle point
		typename Container::iterator middle = first + (last - first) / 2;
		// recusively split to left and right
		merge_sort2(cont, first, middle);
		merge_sort2(cont, middle, last);
		// merge in the sorted order back to original container
		merge(cont, first, middle, last);	
	}
}

/* Can't use this optimized one because we can't see the performance difference */
// template < typename Iter >
// void	merge_sort(Iter first, Iter last) {
// 	// if only one element, do nothing
// 	if (last - first > 1) {
// 		// find middle point
// 		Iter middle = first + (last - first) / 2;
// 		// recursively split to left and right
// 		merge_sort(first, middle);
// 		merge_sort(middle, last);
// 		// merge in order back
// 		std::inplace_merge(first, middle, last);
// 	}
// }