/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 05:00:43 by user              #+#    #+#             */
/*   Updated: 2023/06/08 21:52:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
    std::cout << "SCAVTRAP constructor called :)" << std::endl;
    this->_hp = 100;
    this->_ep = 50;
    this->_a = 20;
}

ScavTrap::ScavTrap(ScavTrap const &other): ClapTrap(other._name)
{
    std::cout << "SCAVTRAP copy constructor called !!" << std::endl;
    this->_hp = other._hp;
    this->_ep = other._ep;
    this->_a = other._a;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &other)
{
    std::cout << "SCAVTRAP operand constructor called !!" << std::endl;
    if (this == &other)
        return (*this);
    this->_name = other._name;
    this->_hp = other._hp;
    this->_ep = other._ep;
    this->_a = other._a;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "SCAVTRAP denstructor called x(" << std::endl;
}

void    ScavTrap::attack(const std::string &target)
{
    if (this->_ep == 0)
        std::cout << this->_name << " NOEPSOICANTMOVE!" << std::endl;
    else if (this->_hp == 0)
        std::cout << this->_name << " NOHPSOICANTMOVE" << std::endl;
    else
    {
        std::cout << " ScavTrap " << this->_name << " ATTACKS " << target << " , CAUSING " << this->_a << " P O I N T S!" << std::endl;
        this->_ep = this->_ep - 1;
    }
}

void    ScavTrap::GuardGate()
{
    std::cout << "guard gate is called!" << std::endl;
}
