/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:08 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/06 22:18:48 by user             ###   ########.fr       */
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
	if (nbr > 8388607 || nbr < -8388608)
	{
		std::cout << "can not correctly handling" << std::endl;
		exit(1);//exitするかは迷ったが正しくない結果を入れても仕方ない気がするので無しにします
	}
	this->value = nbr << this->fractionalBit;
}

FixNumber::~FixNumber()
{
	std::cout << "delimiter called" << std::endl;
}

FixNumber::FixNumber(const FixNumber &nbr):value(nbr.value)
{
	std::cout << "copy constractor called" << std::endl;
	setRawBits(nbr.value);
}

FixNumber& FixNumber::operator=(const FixNumber &nbr)
{
	std::cout << "copy asaiment operator called" << std::endl;
	if (this == &nbr)
		return (*this);
	setRawBits(nbr.value);
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const FixNumber &tgt)
{
	out << tgt.toFloat();
	return (out);	
}

int	FixNumber::getRawBits()
{
	std::cout << "getRawBits function called" << std::endl;
	return (this->value);
}

void	FixNumber::setRawBits(const int nbr)
{
	std::cout << "setRawBits function called" << std::endl;
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
