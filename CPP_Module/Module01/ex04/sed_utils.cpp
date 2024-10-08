/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_utils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:24:26 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/15 16:33:22 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int sed(std::ofstream &ofs, const char *s1, const char *s2, std::string buff) {
    std::size_t pos = 0;
    std::size_t found = buff.find(s1);
    while (found != std::string::npos) {
        ofs << buff.substr(pos, found - pos) << s2;
        found += strlen(s1);
        pos = found;
        found = buff.find(s1, found);
    }
    ofs << buff.substr(pos);
    return 0;
}