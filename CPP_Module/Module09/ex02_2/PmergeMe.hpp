/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:48:50 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/22 00:41:35 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <vector>
# include <deque>
# include <algorithm>
# include <functional>
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
	std::deque<int>      _c_deque;
	size_t					_size;
	std::vector<size_t>	_jacob_seq;
	
public:
	PmergeMe(std::vector<int> const &input);
	~PmergeMe();
	void	sort_compare();
	static bool     isPositiveNum(std::string argv);
};

std::vector<size_t>	generateJacobSeq(size_t n);
std::vector<size_t>	getInsertionIndices(size_t n);

std::ostream & operator<<(std::ostream &o, std::vector<int> const &rhs);

template < typename Iter, typename T >
Iter binarySearch(Iter first, Iter last, const T& value);

template < typename Iter >
void	fordJohnsonSort(Iter first, Iter last);

template < typename Container >
void	fordJohnsonSort(Container & container);

#endif