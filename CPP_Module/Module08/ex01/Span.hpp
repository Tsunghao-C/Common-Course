/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:13:36 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/16 17:21:28 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>

class Span
{
private:
	unsigned int	_n;
	unsigned int 	_stored;
	std::vector<int>	_cont;
public:
	Span();
	Span(unsigned int n);
	Span(Span const &other);
	Span& operator=(Span const &other);
	~Span();
public:
	void	addNumber(int number);
	unsigned int	shortestSpan()const;
	unsigned int	longestSpan() const;
	void	fillNumbers(unsigned int n);
	void	printAll() const;
public:
	class OutOfRangeException;
	class NoRangeException;
};

#endif