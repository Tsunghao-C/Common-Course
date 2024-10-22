/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:40:55 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/22 17:36:10 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> const &input) : _c_vec(input) {
	for (std::vector<int>::const_iterator it = input.begin(); it != input.end(); ++it) {
		_c_deque.push_back(*it);
	}
	// this->_size = _c_vec.size();
}

PmergeMe::PmergeMe(PmergeMe const &other) { *this = other; }

PmergeMe& PmergeMe::operator=(PmergeMe const &other) {
	if (this != &other) {
		this->_c_vec = other._c_vec;
		this->_c_deque = other._c_deque;
		// this->_size = other._size;
		// this->_jacob_seq = other._jacob_seq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::sort_compare() {
	std::cout << "Before: " << _c_vec << std::endl;
	// do vector sort
	clock_t	vec_start = clock();
	fordJohnsonSort(_c_vec.begin(), _c_vec.end());
	// merge_sort(_c_vec.begin(), _c_vec.end());
	clock_t	vec_end = clock();
	std::cout << "After:  " << _c_vec << std::endl;

	// do list sort
	clock_t	deque_start = clock();
	fordJohnsonSort(_c_deque.begin(), _c_deque.end());
	// merge_sort(_c_deque.begin(), _c_deque.end());
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
	while (JacobSeq.back() < n) {
		size_t next	= JacobSeq[i - 1] + 2 * JacobSeq[i - 2];
		if (next >= n) {
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
	std::cout << "size n is: " << n << std::endl;
	std::cout << "got Jacob seg, jocob size is: " << JacobSeq.size() << std::endl;
	for (size_t	i = JacobSeq.size() - 1; i > 0; --i) {
		if (JacobSeq[i] < n) {
			indices.push_back(JacobSeq[i]);
		}
		for (size_t j = JacobSeq[i] - 1; j > JacobSeq[i - 1]; --j) {
			if (j < n) {
				indices.push_back(j);
			}
		}
	}
	for (size_t i = 1; i < n && i <= JacobSeq[0] + 1; ++i) {
		indices.push_back(i);
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

template < typename Iter >
void	fordJohnsonSort(Iter first, Iter last) {
	typedef typename std::iterator_traits<Iter>::value_type T;
	typedef typename std::vector<T>::iterator VecIterator;

	size_t	diff = std::distance(first, last);
	if (diff <= 1) return ;

	// Step 1: Create sorted pairs
	std::vector<std::pair<T, T> > pairs;
	std::vector<T> remaining;
	
	Iter it = first;
	while (std::distance(it, last) >= 2) {
		T first_val = *it;
		++it;
		T second_val = *it;
		++it;

		if (second_val < first_val) {
			std::swap(first_val, second_val);
		}
		pairs.push_back(std::make_pair(first_val, second_val));
	}
	
	if (it != last) {
		remaining.push_back(*it);
	}
	std::cout << "step 1 finish\n";
	 

	// Step 2: Recusively sort Larger elements
	std::vector<T> larger;
	for (typename std::vector<std::pair<T, T > >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it) {
		larger.push_back(pair_it->second);
	}

	if (larger.size() > 1) {
		fordJohnsonSort(larger.begin(), larger.end());
	}
	std::cout << "step 2 finish\n";

	// Step 3: Create main chain with sorted larger elements
	std::vector<T> mainChain;
	mainChain.reserve(diff);

	if (!pairs.empty()) {
		mainChain.push_back(pairs[0].first);
	}
	
	mainChain.insert(mainChain.end(), larger.begin(), larger.end());
	std::cout << "step 3 finish\n";
	// Step 4: Insert remaining elements using Jacobsthal numbers
	std::vector<T> pending;
	for (typename std::vector<std::pair<T, T > >::iterator pair_it = pairs.begin() + 1; pair_it != pairs.end(); ++ pair_it) {
		pending.push_back(pair_it->first);
	}
	pending.insert(pending.end(), remaining.begin(), remaining.end());
	std::cout << "got pending: " << pending.size() << std::endl;
	std::vector<size_t> insertionOrder = getInsertionIndices(pending.size());
	std::cout << "got insertion order: " << insertionOrder << std::endl;
	// do insertions
	for (std::vector<size_t>::iterator order_it = insertionOrder.begin(); order_it != insertionOrder.end(); ++order_it) {
		if (*order_it < pending.size()) {
			T value = pending[*order_it];
			VecIterator pos = binarySearch(mainChain.begin(), mainChain.end(), value);
			mainChain.insert(pos, value);
		}
	}
	std::cout << "insertion finish\n";
	// copy back to original container
	std::copy(mainChain.begin(), mainChain.end(), first);
}

template < typename Container >
void	fordJohnsonSort(Container & container) {
	fordJohnsonSort(container.begin(), container.end());
}