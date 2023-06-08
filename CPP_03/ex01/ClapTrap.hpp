/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:17:48 by user              #+#    #+#             */
/*   Updated: 2023/06/09 00:35:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string         _name;
        unsigned int        _hp;
        unsigned int        _ep;
        unsigned int        _a;
    
    public:
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &other);
        ClapTrap &operator=(ClapTrap const &other);
        ~ClapTrap();
        virtual void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

#endif