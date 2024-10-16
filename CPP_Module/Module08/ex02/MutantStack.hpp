/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:20:05 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/16 15:30:50 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template < typename T >
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(MutantStack<T> const &other);
	MutantStack<T>& operator=(MutantStack<T> const &other);
	~MutantStack();
public:
	// 1. use typedef to shorten the definition of iterator and const_iterator
	typedef typename std::stack<T>::container_type::iterator	iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
	/* the typename above is necessary to resolve the ambiguity of the dependent name T */
	
	// 2. prototype the methods of begin and end the returns the "iterator"
	iterator	begin(); 
	iterator	end();
	const_iterator	begin() const;
	const_iterator	end() const;
};

# include "MutantStack.tpp"

#endif