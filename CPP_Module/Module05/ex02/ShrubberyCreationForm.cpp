/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:27:56 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/08 14:26:18 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation", 145, 137) {
	this->setTarget(target);
	std::cout << "A Shruberry is created by default\n" << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), 145, 137) {
	this->setTarget(other.getTarget());
	std::cout << "A Shrubeery is copied\n" << *this << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "A Shruberry is destroyed" << std::endl;
}

void	ShrubberyCreationForm::rollout() const{
	std::string		filename = this->getTarget() + "_shrubbery";
	std::ofstream	ofs(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (ofs.fail()) {
		throw std::exception();
	}
	ofs << 
	"                   O                         \n" <<
	"                  ***                        \n" <<
	"                 **O**                       \n" <<
	"                *******                      \n" <<
	"               *********                     \n" <<
	"              ***********                    \n" <<
	"               ******o**                     \n" <<
	"              ***********                    \n" <<
	"             ****o********                   \n" <<
	"            ***************                  \n" <<
	"           ****o***o********                 \n" <<
	"          *******************                \n" <<
	"        ***********************              \n" <<
	"           *****O***********                 \n" <<
	"          **********o********                \n" <<
	"         ****************o****               \n" <<
	"        **O********************              \n" <<
	"       ***********o********O****             \n" <<
	"     *****************************           \n" <<
	"         *********************               \n" <<
	"        ***o*******************              \n" <<
	"       ***********o*******o*****             \n" <<
	"      ***************************            \n" <<
	"     ***********************O*****           \n" <<
	"    ***O***************************          \n" <<
	"  ***********************************        \n" <<
	"       *************************             \n" <<
	"      *******o********o**********            \n" <<
	"     *****************************           \n" <<
	"    **************o****************          \n" <<
	"   *************************O*******         \n" <<
	"  *****O*****************************        \n" <<
	"**************o************************      \n" <<
	"      ***************************            \n" <<
	"     *************o***************           \n" << 
    "    ***********o*******************          \n" <<
	"   **************************O******         \n" <<
	"  ***o******************O************        \n" <<
	"***o***********o****************o******      \n" <<
	"                  ###                        \n" <<
	"                  ###                        \n" <<
	"                  ###                        \n" <<
	"              ###########                    \n" <<
	"              ###########                    " << std::endl;
}