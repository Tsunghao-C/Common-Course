/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:48:50 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/23 17:50:18 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <vector>
# include <deque>
# include <list>
# include <algorithm>
# include <ctime>
# include <exception>

class PmergeMe
{
private:
	/* data */
	PmergeMe();
	PmergeMe(PmergeMe const &other);
	PmergeMe&   operator=(PmergeMe const &other);
	std::vector<int>    _c_vec;
	std::vector<int>    _c_vec2;
	std::deque<int>     _c_deque;
	std::list<int>		_c_list;
	// int					_compares;
	// size_t					_size;
	// std::vector<size_t>	_jacob_seq;
	
public:
	PmergeMe(std::vector<int> const &input);
	~PmergeMe();
	void	sort_compare();
	static bool     isPositiveNum(std::string argv);
};

template <typename T>
std::ostream & operator<<(std::ostream &o, std::vector<T> const &rhs);

std::vector<size_t>	generateJacobSeq(size_t n);
std::vector<size_t>	getInsertionIndices(size_t n);

template < typename Iter, typename T >
Iter binarySearch(Iter first, Iter last, const T& value, size_t *_compares);

template < template <typename, typename> class Container, typename T, typename Alloc >
size_t	merge_insertion_sort(Container<T, Alloc> &cont,
		typename Container<T, Alloc>::iterator first, typename Container<T, Alloc>::iterator last);

template < typename Container >
size_t	merge(Container &cont, typename Container::iterator first, typename Container::iterator middle, typename Container::iterator last);

template < typename Container >
size_t	merge_sort2(Container &cont, typename Container::iterator first, typename Container::iterator last);

#endif