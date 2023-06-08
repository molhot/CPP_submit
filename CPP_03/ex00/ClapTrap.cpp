/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:17:44 by user              #+#    #+#             */
/*   Updated: 2023/06/08 20:31:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):_name(name), _a(0), _ep(10), _hp(10)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other):_name(other._name), _a(other._a), _ep(other._ep), _hp(other._hp)
{
    std::cout << "ClapTrap copyconstructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &other)
{
    std::cout << "ClapTrap oparator constructor called" << std::endl;
    if (this == &other)
        return (*this);
    this->_name = other._name;
    this->_hp = other._hp;
    this->_ep = other._ep;
    this->_a = other._a;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string &target)
{
    if (this->_ep == 0)
        std::cout << this->_name << " no ep, so this machine can't move" << std::endl;
    else if (this->_hp == 0)
        std::cout << this->_name << " no hp, so this machine can't move" << std::endl;
    else
    {
        std::cout << " ClapTrap " << this->_name << " attacks " << target << " , causing " << this->_a << " points of damage!" << std::endl;
        this->_ep = this->_ep - 1;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    size_t  tmp_hp;

    if (this->_hp == 0)
        std::cout << this->_name << " no hp, so this machine can't dameged more than now" << std::endl;
    else
    {
        std::cout << this->_name << " attacked " << amount << "damage" << std::endl;
        tmp_hp = this->_hp;
        this->_hp = this->_hp - amount;
        if (tmp_hp < this->_hp)
            this->_hp = 0;
        std::cout << this->_name << " now hp is " << this->_hp << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_ep == 0)
        std::cout << this->_name << " no ep, so this machine can't move" << std::endl;
    else if (this->_hp == 0)
        std::cout << this->_name << " no hp, so this machine can't removed" << std::endl;
    else
    {
        std::cout << this->_name << " repaired" << amount << "hp!" << std::endl;
        this->_ep = this->_ep - 1;
        this->_hp = this->_hp + amount;
        std::cout << this->_name << " now hp is " << this->_hp << std::endl;
    }
}

