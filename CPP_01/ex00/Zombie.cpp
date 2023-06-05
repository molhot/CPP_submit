/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:55:46 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/05 21:13:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "noting to do" << std::endl;
}

Zombie::Zombie(std::string name)
{
	std::cout << "initialized" << std::endl;
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this-> name << "is destructed" << std::endl;
}

Zombie::Zombie(const Zombie &cpzombie)
{
	std::cout << "copyconstruncter called" << std::endl;
	this->name = cpzombie.name;
}

Zombie& Zombie::operator=(const Zombie &zpy)
{
	if (this == &zpy)
		return (*this);
	std::cout << "operator constructer is called" << std::endl;
	this->name = zpy.name;
	std::cout << "this address is " << this << std::endl;
	std::cout << "opponent address is " << &zpy << std::endl;
	return (*this);
}

void	Zombie::makesound()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
