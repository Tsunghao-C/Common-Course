/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:48:16 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/18 12:09:33 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <iomanip>
# include <stack>
# include <algorithm>
# include <string>
# include <limits>
# include <exception>

class RPN
{
private:
    /* data */
    RPN();
    RPN(RPN const &other);
    RPN& operator=(RPN const &other);
    std::stack<std::string>     _input;
    bool    parse_input(std::string input);
    static bool isoperator(int c);
public:
    RPN(std::string const &input);
    ~RPN();
    double  do_rpn_cal();
};


#endif