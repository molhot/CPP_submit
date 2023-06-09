/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:08 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/09 21:25:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

FixNumber::FixNumber():value(0)
{
	std::cout << "default constractor called" << std::endl;
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

int	FixNumber::getRawBits() const
{
	std::cout << "getRawBits function called" << std::endl;
	return (this->value);
}

void	FixNumber::setRawBits(const int nbr)
{
	std::cout << "setRawBits function called" << std::endl;
	this->value = nbr;
}