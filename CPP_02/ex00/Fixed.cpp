/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:08 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/27 21:55:58 by mochitteiun      ###   ########.fr       */
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
	set_value(nbr.value);
}

FixNumber& FixNumber::operator=(const FixNumber &nbr)
{
	std::cout << "copy asaiment operator called" << std::endl;
	set_value(nbr.value);
	return (*this);
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