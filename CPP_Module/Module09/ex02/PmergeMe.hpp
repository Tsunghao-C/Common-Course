/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:48:50 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/18 13:55:10 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
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
    std::list<int>      _c_list;
    
public:
    PmergeMe(std::string const &input);
    ~PmergeMe();
};

#endif