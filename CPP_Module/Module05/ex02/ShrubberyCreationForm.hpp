/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:22:45 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/27 12:21:11 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SRUBBERYCREATIONFORM_HPP
# define SRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    /* data */
public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();
    /* Exec action */
    void    rollout() const;
};


#endif