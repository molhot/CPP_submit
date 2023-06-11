/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:17:48 by user              #+#    #+#             */
/*   Updated: 2023/06/11 13:27:58 by user             ###   ########.fr       */
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
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &other);
        ClapTrap &operator=(ClapTrap const &other);
        ~ClapTrap();
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        std::string    obtain_name() const;
        unsigned int    obtain_hp() const;
        unsigned int    obtain_ep() const;
        unsigned int    obtain_a() const;
};

#endif