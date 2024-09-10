/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:12:42 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/10 16:52:43 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

class	Sample {

	public:

		int	foo;
		char	coo;
		float const noo;
		Sample (int p1, char p2, float const p3);
		~Sample (void);
		void	bar(void) const;
		// by adding "const", it means that the variables within the "{}"
		// shall not be re-assigned or changed.
		// Adding "const" to all the variables that shouldn't change is a
		// good practice, especially for Object-oriented programing because
		// later when you extend your classes, it could easily blow up if
		// you don't add "const" to protect certain variables.

		int	getFoo(void) const;		// getter
		void	setFoo(int value);	// setter
		// Create a member function that allows user to access or update the value 
		// in the private part in a class

	private:

		int	_foo;
		void	_bar(void) const;

		// Every private identifiers can only be reached in side the class,
		// which means in the constructor or deconstructors
		// keep all the private identifiers starting with a prefix of "_"
};

/* Class vs Struct */

// The way to declare a struct in CPP is the same as a Class.
// The main difference is that if you don't specify the visibility, be defaut:
// 	- class:  public
// 	- struct: private
// In CPP, it is a common practice to use "class" instead of "struct"

struct	Sample2 {

	int	foo;
	void	bar(void) const;
	Sample2 (void);
	~Sample2 (void);
};

#endif
