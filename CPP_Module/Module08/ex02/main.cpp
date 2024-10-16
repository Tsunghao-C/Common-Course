/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:36:00 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/16 13:48:46 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <algorithm>

int     main() {
	MutantStack<int> mstack;
	std::list<int>	lst;
	mstack.push(5);
	lst.push_back(5);
	mstack.push(17);
	lst.push_back(17);
	std::cout << "----Mutant Stack----" << std::endl;
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	std::cout << "---- List ----" << std::endl;
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	mstack.push(3); mstack.push(5); mstack.push(737); mstack.push(0);
	lst.push_back(3); lst.push_back(5); lst.push_back(737); lst.push_back(0);
	MutantStack<int>::iterator it = mstack.begin(); 
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "----Mutant Stack Iteration----" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "----List Iteration----" << std::endl;
	std::list<int>::iterator itl = lst.begin();
	std::list<int>::iterator itle = lst.end();
	while (itl != itle) {
		std::cout << *itl << std::endl;
		++itl;
	}
	std::stack<int> s(mstack);
	return 0;
}
