/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:53:54 by user              #+#    #+#             */
/*   Updated: 2023/06/08 22:05:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "FlagTrap Constructor called" << std::endl;
    this->_hp = 100;
    this->_ep = 100;
    this->_a = 30;
}

FragTrap::FragTrap(FragTrap const &other): ClapTrap(other._name)
{
    std::cout << "FLAGTRAP copy constructor called !!" << std::endl;
    this->_hp = other._hp;
    this->_ep = other._ep;
    this->_a = other._a;
}

FragTrap& FragTrap::operator=(FragTrap const &other)
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

FragTrap::~FragTrap()
{
    std::cout << "FlagTrap Desstructor called" << std::endl;
}

void    FragTrap::highFivesGuys()
{
    std::cout << "High five !!" << std::endl;
}