/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 05:00:48 by user              #+#    #+#             */
/*   Updated: 2023/05/04 05:12:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class   ScavTrap: public ClapTrap
{
    private:
        ScavTrap();

    public:
        ScavTrap(std::string name);
        ~ScavTrap();
        void    GuardGate();
};