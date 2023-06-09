/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:59:00 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/07 23:13:47 by user             ###   ########.fr       */
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
	this->setType(weapon.getType());
}

Weapon& Weapon::operator=(const Weapon &weapon)
{
	this->setType(weapon.getType());
	return (*this);
}

const std::string	&Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}