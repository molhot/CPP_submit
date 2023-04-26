/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:59:00 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/27 00:43:56 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
	
}

Weapon::Weapon(std::string weapon):type(weapon)
{
	
}

Weapon::Weapon(const Weapon &weapon)
{
	if (&weapon == NULL)
		return ;
	this->setType(weapon.getType());
}

Weapon& Weapon::operator=(const Weapon &weapon)
{
	this->setType(weapon.getType());
	return (*this);
}

std::string	Weapon::getType() const
{
	if (this == NULL)
		std::cout << "no __ weapon __ ...";
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}