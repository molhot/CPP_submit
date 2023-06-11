/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:53:28 by user              #+#    #+#             */
/*   Updated: 2023/06/11 21:36:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FlagTrap_HPP
#define FlagTrap_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    private:
        
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &other);
        FragTrap &operator=(FragTrap const &other);
        ~FragTrap();
        void    highFivesGuys(void);
};

#endif