/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:54:43 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/16 18:26:25 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_HPP 
# define INTEGER_HPP

# include <iostream>
# include <string>

class Integer
{
private:
	/* data */
	int		_n;
public:
	Integer(int	const n);
	~Integer();
	
	int		getValue( void ) const;
	
	Integer&	operator=( Integer const & rhs);
	//	The return is a REF to Integer to make chained operators possible
	//	ex. a = b = c = d
	Integer		operator+( Integer const & rhs) const;
	//	The return is a new Integer to make chained operators possible
	//	ex. a + b + c + d
	//	The arguments are actually "TWO". There is a hidden arguement
	//	which is the instance of the current instance LHS (this).
	//	ex. 1 + 1 -> 1 +(1)
	//	Using the keyword "operator" to overload (re-define) the behavior
	//	of an existing operator ONLY WITHIN THE SCOPE OF THE CLASS.
};

std::ostream & operator<<(std::ostream & o, Integer const & rhs);

#endif

// 1. The overload arithmatic must be natural
// 2. The overload operator should make sense and easy to read
// 3. Operator overload are powerfull but easy to go wrong. Use wisely and carefully.
// Examples of operator overload:
// a. You are handling vectors are matrix, and you want to redefine the "+" operator to matrix operator.
// b. You are handling complex number, so you redefine the "+" operators accordingly