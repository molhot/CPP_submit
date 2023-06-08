/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:17:48 by user              #+#    #+#             */
/*   Updated: 2023/06/09 00:11:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string _name;
        size_t      _hp;
        size_t      _ep;
        size_t      _a;
    
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