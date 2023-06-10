/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:08 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/10 18:33:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_value(0)
{
	std::cout << "default constractor called" << std::endl;
}

Fixed::Fixed(const float &nbr):_value(0)
{
	std::cout << "Float construcor called" << std::endl;
	std::cout << "this float is " << nbr << std::endl;
	this->_value = roundf(nbr * (1 << this->_fractionalBit));
	std::cout << "input _value is " << this->_value << std::endl;
}

Fixed::Fixed(const int &nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = nbr << this->_fractionalBit;
}

Fixed::~Fixed()
{
	std::cout << "delimiter called" << std::endl;
}

Fixed::Fixed(const Fixed &nbr):_value(nbr._value)
{
	std::cout << "copy constractor called" << std::endl;
	setRawBits(nbr._value);
}

Fixed& Fixed::operator=(const Fixed &nbr)
{
	std::cout << "copy asaiment operator called" << std::endl;
	if (this == &nbr)
		return (*this);
	setRawBits(nbr._value);
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &tgt)
{
	out << tgt.toFloat();
	return (out);	
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(const int nbr)
{
	std::cout << "setRawBits function called" << std::endl;
	this->_value = nbr;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_fractionalBit));
}

int	Fixed::toInt(void) const
{
	return (this->_value / (1 << this->_fractionalBit));
}
