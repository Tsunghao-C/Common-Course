/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:40:55 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/23 23:37:01 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> const &input) : _c_vec(input), _c_vec2(input) {
	for (std::vector<int>::const_iterator it = input.begin(); it != input.end(); ++it) {
		_c_deque.push_back(*it);
		_c_deque2.push_back(*it);
		_c_list.push_back(*it);
		_c_list2.push_back(*it);
	}
}

PmergeMe::PmergeMe(PmergeMe const &other) { *this = other; }

PmergeMe& PmergeMe::operator=(PmergeMe const &other) {
	if (this != &other) {
		this->_c_vec = other._c_vec;
		this->_c_vec2 = other._c_vec2;
		this->_c_deque = other._c_deque;
		this->_c_deque2 = other._c_deque2;
		this->_c_list = other._c_list;
		this->_c_list = other._c_list2;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::sort_compare() {
	std::cout << "Before: " << _c_vec << std::endl;
	// do vector merge-insertion sort
	clock_t	vec_start = clock();
	size_t num_compares_vec = merge_insertion_sort(_c_vec, _c_vec.begin(), _c_vec.end());
	clock_t	vec_end = clock();
	std::cout << "After:  " << _c_vec << std::endl;

	// do deque merge-insertion sort
	clock_t	deque_start = clock();
	size_t num_compares_deq = merge_insertion_sort(_c_deque, _c_deque.begin(), _c_deque.end());
	clock_t deque_end = clock();

	// do list merge-insertion sort
	clock_t	list_start = clock();
	size_t num_compares_lst = merge_insertion_sort(_c_list, _c_list.begin(), _c_list.end());
	clock_t list_end = clock();

	// do vector merge sort
	clock_t	vec2_start = clock();
	size_t num_compares_vec2 = merge_sort2(_c_vec, _c_vec.begin(), _c_vec.end());
	clock_t	vec2_end = clock();
	
	// do deque merge sort
	clock_t	deque2_start = clock();
	size_t num_compares_deq2 = merge_sort2(_c_deque2, _c_deque2.begin(), _c_deque2.end());
	clock_t	deque2_end = clock();
	
	// do list merge sort
	clock_t	list2_start = clock();
	size_t num_compares_lst2 = merge_sort2(_c_list2, _c_list2.begin(), _c_list2.end());
	clock_t	list2_end = clock();
	
	std::cout << "Time to process a range of " << _c_vec.size() << " elements with std::[vector] : ";
	std::cout << std::fixed << std::setprecision(5) << static_cast<double>(vec_end - vec_start) / CLOCKS_PER_SEC << " s. "
			<< "Number of compares: " << num_compares_vec << std::endl;
	std::cout << "Time to process a range of " << _c_vec2.size() << " elements with std::[vector] : ";
	std::cout << std::fixed << std::setprecision(5) << static_cast<double>(vec2_end - vec2_start) / CLOCKS_PER_SEC << " s. "
			<< "Number of compares: " << num_compares_vec2 <<  " (merge_sort)" << std::endl;
	std::cout << "Time to process a range of " << _c_deque.size() << " elements with std::[deque]  : ";
	std::cout << std::fixed << std::setprecision(5) << static_cast<double>(deque_end - deque_start) / CLOCKS_PER_SEC << " s. "
			<< "Number of compares: " << num_compares_deq << std::endl;
	std::cout << "Time to process a range of " << _c_deque2.size() << " elements with std::[deque]  : ";
	std::cout << std::fixed << std::setprecision(5) << static_cast<double>(deque2_end - deque2_start) / CLOCKS_PER_SEC << " s. "
			<< "Number of compares: " << num_compares_deq2 <<  " (merge_sort)" << std::endl;
	std::cout << "Time to process a range of " << _c_list.size() << " elements with std::[list]   : ";
	std::cout << std::fixed << std::setprecision(5) << static_cast<double>(list_end - list_start) / CLOCKS_PER_SEC << " s. "
			<< "Number of compares: " << num_compares_lst << std::endl;
	std::cout << "Time to process a range of " << _c_list2.size() << " elements with std::[list]   : ";
	std::cout << std::fixed << std::setprecision(5) << static_cast<double>(list2_end - list2_start) / CLOCKS_PER_SEC << " s. "
			<< "Number of compares: " << num_compares_lst2  << " (merge_sort)" << std::endl;
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
Iter binarySearch(Iter first, Iter last, const T& value, size_t *_compares) {
	Iter	it;
	typename std::iterator_traits<Iter>::difference_type count, step;
	count = std::distance(first, last);

	while (count > 0) {
		it = first;
		step = count / 2;
		std::advance(it, step);

		*_compares += 1;
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
size_t	merge_insertion_sort(Container<T, Alloc> &cont,
		typename Container<T, Alloc>::iterator first,
		typename Container<T, Alloc>::iterator last)
{
	typedef typename Container<T, Alloc>::iterator	cont_it;
	typedef typename Alloc::template rebind<std::pair<T, T> >::other PairAlloc;
	typedef typename Container<std::pair<T, T>, PairAlloc>::iterator pair_it;
	(void)cont;
	size_t	compares = 0;
	
	size_t	diff = std::distance(first, last);
	if (diff <= 1) {return compares;}
	
	// Step 1: create n/2 pairs
	Container<std::pair<T, T>, PairAlloc> pairs;
	Container<T, Alloc>		leftover;
	
	cont_it	it = first;
	while (std::distance(it, last) >= 2) {
		T	first_val = *(it++);
		T	second_val = *(it++);
		compares++;
		if (second_val < first_val) {
			std::swap(first_val, second_val);
		}
		pairs.push_back(std::make_pair(first_val, second_val));
	}
	if (it != last) { leftover.push_back(*it); }
	// // Step 1 printing check
	
	// Step 2: Recusively sort the larger number
	Container<T, Alloc>		mainChain;
	for (pair_it itp = pairs.begin(); itp != pairs.end(); ++itp) {
		mainChain.push_back(itp->second);
	}
	if (mainChain.size() >= 2)
		compares += merge_insertion_sort(mainChain, mainChain.begin(), mainChain.end());
	// // Step 2 printing check (largers should be sorted by here)
	
	// Step 3: Form main chain and pending based on sorted largers
	Container<T, Alloc>		pending;
	// since largers are sorted now, it is the mainChain directly. But for pending, need to find the corresponding first element in pairs
	for (cont_it it = mainChain.begin(); it != mainChain.end(); ++it) {
		// mainChain.push_back(*it);
		for (pair_it itp = pairs.begin(); itp != pairs.end(); ++itp) {
			if (itp->second == *it) {
				pending.push_back(itp->first);
				break;
			}
		}
	}
	// // Step 3 printing check

	// Step 4: Insert pending stuffs based on Jacobsthal sequence
	std::vector<size_t>		indices = getInsertionIndices(pending.size());
	for (size_t i = 0; i < indices.size(); i++) {
		size_t	probe = indices[i];
		cont_it insertTarget = pending.begin();
		if (probe == 1) {
			mainChain.insert(mainChain.begin(), *insertTarget);
		} else {
			std::advance(insertTarget, probe - 1);
			T	target_val;
			for (pair_it itp = pairs.begin(); itp != pairs.end(); ++itp) {
				if (itp->first == *insertTarget) {
					target_val = itp->second;
					break;
				}
			}
			// finding the corresponding larger number, this one don't need to compare!!!
			cont_it searchEnd;
			for (searchEnd = mainChain.begin(); searchEnd != mainChain.end(); ++searchEnd) {
				if (*searchEnd == target_val) { break; }
			}
			cont_it	insertPos = binarySearch(mainChain.begin(), searchEnd, *insertTarget, &compares);
			mainChain.insert(insertPos, *insertTarget);
		}
	}
	if (!leftover.empty()) {
		cont_it insertPos = binarySearch(mainChain.begin(), mainChain.end(), *leftover.begin(), &compares);
		mainChain.insert(insertPos, *leftover.begin());
	}

	// Step 5: copy back to original container
	std::copy(mainChain.begin(), mainChain.end(), first);
	return compares;
}

	// // Step 1 printing check
	// std::cout << " ^^^^^^ Pairs ^^^^^^^\n";
	// for (pair_it itp = pairs.begin(); itp != pairs.end(); ++itp) {
	// 	std::cout << " (" << itp->first << ", " << itp->second << ")"; }
	// std::cout << "\n ###### LeftOver #########\n";
	// for (cont_it itl = leftover.begin(); itl != leftover.end(); ++itl) {
	// 	std::cout << " " << *itl; }
	// std::cout << std::endl;

	// // Step 2 printing check (largers should be sorted by here)
	// std::cout << "********** MainChain (Larger) **********\n";
	// for (cont_it it = mainChain.begin(); it != mainChain.end(); ++it) {
	// 	std::cout << " " << *it; }
	// std::cout << std::endl;

	// // Step 3 printing check
	// std::cout << "********** mainChain **********\n";
	// for (cont_it it = mainChain.begin(); it != mainChain.end(); ++it) {
	// 	std::cout << " " << *it; }
	// std::cout << "\n********** pending **********\n";
	// for (cont_it it = pending.begin(); it != pending.end(); ++it) {
	// 	std::cout << " " << *it; }
	// std::cout << std::endl;

// Adding merge sort to compare the number of comps

template < typename Container >
size_t	merge(Container &cont, typename Container::iterator first, typename Container::iterator middle, typename Container::iterator last) {
	typedef	typename Container::iterator	c_it;
	typename std::iterator_traits<c_it>::difference_type count;
	(void)cont;
	size_t	compares = 0;
	
	count = std::distance(first, last);
	Container	tmp(count);
	c_it	left = first;
	c_it	right = middle;
	c_it	tmp_it = tmp.begin();

	// sorting and copy to tmp
	while (std::distance(left, middle) > 0 && std::distance(right, last) > 0) {
		compares++;
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
	while (std::distance(left, middle) > 0) {
		*tmp_it = *left;
		++left;
		++tmp_it;
	}
	while (std::distance(right, last) > 0) {
		*tmp_it = *right;
		++right;
		++tmp_it;
	}	
	// overwrite sorted tmp to original container
	std::copy(tmp.begin(), tmp.end(), first);
	return compares;
}

template < typename Container >
size_t	merge_sort2(Container &cont, typename Container::iterator first, typename Container::iterator last) {
	typedef typename Container::iterator	c_it;
	typename std::iterator_traits<c_it>::difference_type count;
	count = std::distance(first, last);
	size_t	compares = 0;
	if (count > 1) {
		// find middle point
		c_it	middle = first;
		std::advance(middle, count / 2);
		// recusively split to left and right
		compares += merge_sort2(cont, first, middle);
		compares += merge_sort2(cont, middle, last);
		// merge in the sorted order back to original container
		compares += merge(cont, first, middle, last);	
	}
	return compares;
}