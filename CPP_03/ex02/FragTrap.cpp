/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:53:54 by user              #+#    #+#             */
/*   Updated: 2023/05/04 15:06:13 by user             ###   ########.fr       */
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

FragTrap::~FragTrap()
{
    std::cout << "FlagTrap Desstructor called" << std::endl;
}

void    FragTrap::highFivesGuys()
{
    std::cout << "High five !!" << std::endl;
}