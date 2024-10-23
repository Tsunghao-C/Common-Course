/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:40:55 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/23 16:16:30 by tsuchen          ###   ########.fr       */
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
	merge_insertion_sort(_c_vec, _c_vec.begin(), _c_vec.end());
	clock_t	vec_end = clock();
	std::cout << "After:  " << _c_vec << std::endl;

	// do deque sort
	clock_t	deque_start = clock();
	merge_insertion_sort(_c_deque, _c_deque.begin(), _c_deque.end());
	clock_t deque_end = clock();
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

template <typename T>
std::ostream & operator<<(std::ostream &o, std::vector<T> const &rhs) {
	for (typename std::vector<T>::const_iterator it = rhs.begin(); it != rhs.end(); ++it) {
		o << " " << *it;	
	}
	return o;
}

// n = 0 -> {}
// n = 1 -> {0}
// n = 2 -> {0, 1, 1}
// n = 3 -> {0, 1, 1, 1(3)}
// n = 4 -> {0, 1, 1, 2(3)}
// n = 5 -> {0, 1, 1, 3}

// 0, 1, 1, 3, 5, 11, 21...
// [11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1,]

std::vector<size_t>    generateJacobSeq(size_t n) {
	std::vector<size_t>    JacobSeq;
	if (n == 0) {
		return JacobSeq;
	}
	JacobSeq.push_back(0);
	if (n == 1) {
		return JacobSeq;
	}
    JacobSeq.push_back(1);
	size_t i = 2;
	while (JacobSeq.back() <= n) {
		size_t next	= JacobSeq[i - 1] + 2 * JacobSeq[i - 2];
		if (next > n) {
			break;
		}
		JacobSeq.push_back(next);
		++i;		
	}
	return JacobSeq;
}

std::vector<size_t>	getInsertionIndices(size_t n) {
	std::vector<size_t>	JacobSeq = generateJacobSeq(n);
	std::vector<size_t> indices;
	if (n == 0)
		return indices;
	indices.push_back(1);
	if (n == 1)
		return indices;
	for (size_t i = 1; i < JacobSeq.size(); i++) {
		if (JacobSeq[i] > indices.back()) {
			size_t tmp = JacobSeq[i - 1];
			indices.push_back(JacobSeq[i]);
			for (size_t j = JacobSeq[i] - 1; j > tmp; j--) {
				indices.push_back(j);
			}
		}
	}
	for (size_t k = n; k > JacobSeq.back(); k--) {
		indices.push_back(k);
	}
	return indices;
}

template < typename Iter, typename T >
Iter binarySearch(Iter first, Iter last, const T& value) {
	Iter	it;
	typename std::iterator_traits<Iter>::difference_type count, step;
	count = std::distance(first, last);

	while (count > 0) {
		it = first;
		step = count / 2;
		std::advance(it, step);

		if (*it < value) {
			first = ++it;
			count -= step + 1;
		} else {
			count = step;
		}
	}
	return first;
}

template < template <typename, typename> class Container, typename T, typename Alloc >
void	merge_insertion_sort(Container<T, Alloc> &cont,
		typename Container<T, Alloc>::iterator first,
		typename Container<T, Alloc>::iterator last)
{
	// Step 1: create n/2 pairs
	typedef typename Container<T, Alloc>::iterator	cont_it;
	typedef typename Alloc::template rebind<std::pair<T, T> >::other PairAlloc;
	typedef typename Container<std::pair<T, T>, PairAlloc>::iterator pair_it;
	
	size_t	diff = std::distance(first, last);
	if (diff <= 1) {return ;}

	(void)cont;
	
	Container<std::pair<T, T>, PairAlloc> pairs;
	Container<T, Alloc>		leftover;
	
	cont_it	it = first;
	while (std::distance(it, last) >= 2) {
		T	first_val = *(it++);
		T	second_val = *(it++);
		if (second_val < first_val) {
			std::swap(first_val, second_val);
		}
		pairs.push_back(std::make_pair(first_val, second_val));
	}
	if (it != last) { leftover.push_back(*it); }
	// // Step 1 printing check
	// std::cout << " ^^^^^^ Pairs ^^^^^^^\n";
	// for (pair_it itp = pairs.begin(); itp != pairs.end(); ++itp) {
	// 	std::cout << " (" << itp->first << ", " << itp->second << ")"; }
	// std::cout << "\n ###### LeftOver #########\n";
	// for (cont_it itl = leftover.begin(); itl != leftover.end(); ++itl) {
	// 	std::cout << " " << *itl; }
	// std::cout << std::endl;
	
	// Step 2: Recusively sort the larger number
	Container<T, Alloc>		largers;
	for (pair_it itp = pairs.begin(); itp != pairs.end(); ++itp) {
		largers.push_back(itp->second);
	}
	if (largers.size() >= 2)
		merge_insertion_sort(largers, largers.begin(), largers.end());
	// // Step 2 printing check (largers should be sorted by here)
	// std::cout << "********** Larger **********\n";
	// for (cont_it it = largers.begin(); it != largers.end(); ++it) {
	// 	std::cout << " " << *it; }
	// std::cout << std::endl;
	
	// Step 3: Form main chain and pending based on sorted largers
	Container<T, Alloc>		mainChain;
	Container<T, Alloc>		pending;
	// since largers are sorted, push directly to mainChain
	// but for pending, need to find the corresponding first element in pair
	for (cont_it it = largers.begin(); it != largers.end(); ++it) {
		mainChain.push_back(*it);
		for (pair_it itp = pairs.begin(); itp != pairs.end(); ++itp) {
			if (itp->second == *it) {
				pending.push_back(itp->first);
			}
		}
	}
	pending.insert(pending.end(), leftover.begin(), leftover.end());
	// // Step 3 printing check
	// std::cout << "********** mainChain **********\n";
	// for (cont_it it = mainChain.begin(); it != mainChain.end(); ++it) {
	// 	std::cout << " " << *it; }
	// std::cout << "\n********** pending **********\n";
	// for (cont_it it = pending.begin(); it != pending.end(); ++it) {
	// 	std::cout << " " << *it; }
	// std::cout << std::endl;

	// Step 4: Insert pending stuffs based on Jacobsthal sequence
	std::vector<size_t>		indices = getInsertionIndices(pending.size());
	for (size_t i = 0; i < indices.size(); i++) {
		size_t	probe = indices[i];
		if (probe == 1) {
			mainChain.insert(mainChain.begin(), pending[0]);
		} else {
			cont_it	insertPos = binarySearch(mainChain.begin(), mainChain.end(), pending[probe - 1]);
			mainChain.insert(insertPos, pending[probe - 1]);
		}
	}

	// Step 5: copy back to original container
	std::copy(mainChain.begin(), mainChain.end(), first);
}