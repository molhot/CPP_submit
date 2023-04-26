/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:55:46 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 18:55:50 by mochitteiun      ###   ########.fr       */
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
