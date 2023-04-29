/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:08 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/29 17:35:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

FixNumber::FixNumber():value(0)
{
	std::cout << "default constractor called" << std::endl;
}

FixNumber::FixNumber(const float &nbr):value(0)
{
	std::cout << "Float construcor called" << std::endl;
	std::cout << "this float is " << nbr << std::endl;
	this->value = roundf(nbr * (1 << this->fractionalBit));
	std::cout << "input value is " << this->value << std::endl;
}

FixNumber::FixNumber(const int &nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = nbr << this->fractionalBit;
}

FixNumber::~FixNumber()
{
	std::cout << "delimiter called" << std::endl;
}

FixNumber::FixNumber(const FixNumber &nbr):value(nbr.value)
{
	std::cout << "copy constractor called" << std::endl;
	set_value(nbr.value);
}

FixNumber& FixNumber::operator=(const FixNumber &nbr)
{
	std::cout << "copy asaiment operator called" << std::endl;
	set_value(nbr.value);
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const FixNumber &tgt)
{
	out << tgt.toFloat();
	return (out);	
}

int	FixNumber::get_value()
{
	std::cout << "get_value function called" << std::endl;
	return (this->value);
}

void	FixNumber::set_value(const int nbr)
{
	std::cout << "SET_value function called" << std::endl;
	this->value = nbr;
}

float	FixNumber::toFloat(void) const
{
	return ((float)this->value / (float)(1 << this->fractionalBit));
}

int	FixNumber::toInt(void) const
{
	return (this->value / (1 << this->fractionalBit));
}
