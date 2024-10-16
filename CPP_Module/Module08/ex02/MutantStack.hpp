/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:20:05 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/16 13:21:49 by tsuchen          ###   ########.fr       */
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
	typedef typename std::stack<T>::container_type	mstack;
	typedef typename mstack::iterator				iterator;
	typedef typename mstack::const_iterator			const_iterator;
	
	iterator	begin();
	iterator	end();
	const_iterator	begin() const;
	const_iterator	end() const;
};

# include "MutantStack.tpp"

#endif