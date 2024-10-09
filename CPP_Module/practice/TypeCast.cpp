/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeCast.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:41:14 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/09 11:59:07 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <iostream>
#include <exception>
#include <typeinfo>

/* C style type casting example */
// int     main()
// {
// 	int     a = 42;
// 	int 	*b = &a;
	
// 	int	const	*c = b;				// implicit casting for prmotion (Allowed)
// 	int	const	*d = (int const *)b;// explicit casting for prmotion (Allowed)
// 	// int			*e = c;				// implicit casting for demotion (Not allowed)
// 	int			*f = (int *)c;		// explicit casting for demotion (Allowed)
//	int			*g = static_cast<int>c // explicit casting in C++ style
// }

// ********************			FOUR Explicit Type Casting Methods in CPP		************************ //
// 1. Static_cast			-> type conversion at compilation time
// 2. Dynamic_cast			-> type conversion at runtime
// 3. Reinterpret_cast		-> type conversion at compilation, but compiler won't check for you
// 4. Const_cast			-> type conversion handling a const type, BETTER NOT TO USE IT unless you have good reason
// ***************************************************************************************************** //

// ---------------------+-----------+-----------+-----------+---------------+--------------- //
// 		Cast			+	Conv.	|	Reint.	|	Upcast	|	Downcast	|	Type qual.	 //
// ---------------------+-----------+-----------+-----------+---------------+--------------- //
// Implicit				|	Yes		|			|	Yes		|				|				 //
// static_cast			|	Yes		|			|	Yes		|		Yes		|				 //
// dynamic_cast			|			|			|	Yes		|		Yes		|				 //
// const_cast			|			|			|			|				|		Yes		 //
// reinterpret_cast		|			|	Yes		|	Yes		|		Yes		|				 //
// ---------------------+-----------+-----------+-----------+---------------+--------------- //
// Legacy C cast		|	Yes		|	Yes		| 	Yes		|		Yes		|		Yes		 //
// ---------------------+-----------+-----------+-----------+---------------+--------------- //


// ---------------------+-------------------+---------------------------+------------------- //
// 		Cast			+	Semantic check	|		Reliable at run		|	Tested at run	 //
// ---------------------+-------------------+---------------------------+------------------- //
// Implicit				|		Yes			|			Yes				|					 //
// static_cast			|		Yes			|							|					 //
// dynamic_cast			|		Yes			|			Yes				|		Yes			 //
// const_cast			|					|							|					 //
// reinterpret_cast		|					|							|					 //
// ---------------------+-------------------+---------------------------+------------------- //
// Legacy C cast		|					|							|					 //
// ---------------------+-------------------+---------------------------+------------------- //


/* Static cast in CPP */
// class Parent				{};
// class Child1: public Parent {};
// class Child2: public Parent {};
// class Unrelated				{};

// int		main()
// {
// 	Child1		a;								//Reference value

// 	Parent		*b = &a;						//Implicit 'reinterpretion' cast
// 	Parent		*c = (Parent *)&a;				//Explicit 'reinterpretion' cast
	
// 	Parent		*d = &a;						//Implicit upcast	-> OK!
// 	// Child1		*e = d;							//Implicit downcast -> Hell no
// 	Child2		*f = (Child2 *)d;				//Explicit downcast -> Can compile but ARE YOU SUREEEE?
// 	Child2		*g = static_cast<Child2 *>(d);	//Explicit downcast -> Okay I obey
	
// 	// Unrelated	*h = static_cast<Unrelated *>(&a); //Explicit type conversion -> No because not related!
// 	return 0;
// }

// static cast means that the type casting is DONE at compilation time. Once is casted, it is fixed.
// On the contrary, dynamic cast mean the type casting is done during runtime. It is not fixed and can change over runtime.


/* Dynamic cast in CPP */

// class Parent					{public: virtual ~Parent() {}};
// class Child1 : public Parent 	{};
// class Child2 : public Parent	{};

// int		main()
// {
// 	Child1		a;			// Reference value
// 	Parent		*b = &a;	// Implicit upcast -> OK
	
// 	// Explicit downcast
// 	Child1		*c = dynamic_cast<Child1 *>(b);
// 	if (c == NULL) {
// 		std::cout << "Conversion is NOT OK" << std::endl;
// 	} else {
// 		std::cout << "Conversion is OK" << std::endl;
// 	}

// 	// Explicit downcast -- Not valid
// 	try
// 	{
// 		Child2	&d = dynamic_cast<Child2 &>(*b);
// 		std::cout << "Conversion is OK" << std::endl;
// 	}
// 	catch(const std::bad_cast &bc)
// 	{
// 		std::cerr << "Conversion is NOT OK because: " << bc.what() << '\n';
// 	}
	
// 	return 0;
	
// }

/* Reinterpret Cast */

// int		main()
// {
// 	double		a = 42.0153;		// reference value
// 	void		*b = &a;			// implicit upcasting

// 	int			*c = reinterpret_cast<int *>(b);	// Explicit reinterpret asting
// 	int			&d = reinterpret_cast<int &>(b);	// Explicit reinterpret casting
// 	long		e = reinterpret_cast<long>(b);

// 	// Reinterpret cast mean you can cast whatever you want. The compliler won't stop you but you better know what you
// 	// are doing and what you are expecting for.
// 	return 0;
// }

/* Const Cast */

// int		main()
// {
// 	int			a = 42;

// 	int const	*b = &a;					// Implicit promotion -> OK!
// 	// int			*c = b;						// Implicit demotion -> Hell no!
// 	int			*d = const_cast<int *>(b);	// Explicit demotion -> Ok, I obey

// 	// const_cast allows you to cast a const type (immutable) into a mutable type. But usually not a good practice.
// 	// What was const should be const, and you better had a very good reason when you use const_cast
// }

/* cast operators */

// class Foo
// {
// private:
// 	float	_v;
// public:
// 	Foo(float const v) : _v(v) {}
// 	~Foo() {}
	
// 	float	getV(void)	{return this->_v;}
// 	operator float()	{return this->_v;}
// 	operator int()		{return static_cast<int>(this->_v);}
// };

// int		main()
// {
// 	Foo		a(42.042);
// 	float	b = a;
// 	int		c = a;

// 	std::cout << "Foo value: " << a.getV() << std::endl;
// 	std::cout << "Float b  : " << b << std::endl;
// 	std::cout << "Int c    : " << c << std::endl;
// 	return 0;
// }


/* Use of "explicit" keyword */

// ************************************************************************ //

class A	{};
class B {};

class C {

public:
	explicit	C( B const & _ ) { return ; }
				C( A const & _ ) { return ; }

};
// ************************************************************************ //

void	f( C const & _ ) {
	return ;
}

// ************************************************************************ //

int 	main ()
{
	f( A() );		// Implicit conversion from A to C -> OK
	// f( B() );		// Implicit typecasting from B to C -> Not OK because the "explicit" keyword
	f( C(B()) );	// No conversion -> OK

	// The use of explicit keyword is to prevent implicit conversion from happening
	return 0;
}