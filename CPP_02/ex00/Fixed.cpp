/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:08 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/09 23:21:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_value(0)
{
	std::cout << "default constractor called" << std::endl;
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