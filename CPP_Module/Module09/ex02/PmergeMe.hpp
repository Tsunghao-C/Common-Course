/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:48:50 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/18 23:40:30 by tsuchen          ###   ########.fr       */
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
	
public:
	PmergeMe(std::vector<int> const &input);
	~PmergeMe();
	void	sort_compare();
	static bool     isPositiveNum(std::string argv);
};

std::ostream & operator<<(std::ostream &o, std::vector<int> const &rhs);

/* Manually merge and will create tmp containers to see the speed difference */
template < typename Container >
void	merge(Container &cont, typename Container::iterator first, typename Container::iterator middle, typename Container::iterator last);

template < typename Container >
void	merge_sort2(Container &cont, typename Container::iterator first, typename Container::iterator last);


/* Generic sorting method using iterator without creating tmp containers */
// template < typename Iter >
// void	merge_sort(Iter first, Iter last);

#endif