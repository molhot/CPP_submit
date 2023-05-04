/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 05:00:48 by user              #+#    #+#             */
/*   Updated: 2023/05/04 15:51:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_HPP
#define ScavTrap_HPP

#include "ClapTrap.hpp"

class   ScavTrap: public ClapTrap
{
    private:
        

    public:
        ScavTrap(std::string name);
        // ScavTrap(ScavTrap const &sub);
        // ScavTrap& operator=(ScavTrap const &sub);
        ~ScavTrap();
        void    GuardGate();
};

#endif