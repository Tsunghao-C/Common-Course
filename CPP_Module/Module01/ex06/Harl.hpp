/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:47:17 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/16 11:39:03 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

typedef enum	e_cmpl {
	NONE,
	DEBUG,
	INFO,
	WARNING,
	ERROR
}	t_cmpl;

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	others(void);

		t_cmpl	getComplaintype(std::string level);

	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level);
};

#endif