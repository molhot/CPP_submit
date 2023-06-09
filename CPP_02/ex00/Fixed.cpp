/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:08 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/09 22:39:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():value(0)
{
	std::cout << "default constractor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "delimiter called" << std::endl;
}

Fixed::Fixed(const Fixed &nbr):value(nbr.value)
{
	std::cout << "copy constractor called" << std::endl;
	setRawBits(nbr.value);
}

Fixed& Fixed::operator=(const Fixed &nbr)
{
	std::cout << "copy asaiment operator called" << std::endl;
	if (this == &nbr)
		return (*this);
	setRawBits(nbr.value);
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(const int nbr)
{
	std::cout << "setRawBits function called" << std::endl;
	this->value = nbr;
}