/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 05:00:48 by user              #+#    #+#             */
/*   Updated: 2023/06/11 01:12:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_HPP
#define ScavTrap_HPP

#include "ClapTrap.hpp"

class   ScavTrap: public ClapTrap
{
    private:

    public:
        ScavTrap();//defaultconstructor
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &other);
        ScavTrap &operator=(ScavTrap const &other);
        ~ScavTrap();
        void    guardGate();
        void    attack(const std::string& target);
};

std::ostream &operator<<(std::ostream &out, const ScavTrap &tgt);

#endif