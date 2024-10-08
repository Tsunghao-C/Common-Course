/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:21:30 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/08 19:17:05 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <unistd.h>
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	/* data */
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();
	/* Exec action */
	void	rollout() const;
};

#endif