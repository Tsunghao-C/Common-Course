/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:20:19 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/13 17:37:31 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
    
    std::string     stringVAR = "HI THIS IS BRAIN";
    std::string*    stringPTR = &stringVAR;
    std::string&    stringREF = stringVAR;
    
    std::cout << "Mem Address of stringVAR is     : " << &stringVAR << std::endl;
    std::cout << "Mem Address held by stringPTR is: " << stringPTR << std::endl;
    std::cout << "Mem Address held by stringREF is: " << &stringREF << std::endl;

    std::cout << std::endl;
    std::cout << "Value of stringVAR is         : " << stringVAR << std::endl;
    std::cout << "Value pointed by stringPTR is : " << *stringPTR << std::endl;
    std::cout << "Value pointed by stringREF is : " << stringREF << std::endl;
    
    return 0;
}