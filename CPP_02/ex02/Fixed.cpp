/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:08 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/29 20:26:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

FixNumber::FixNumber():value(0)
{
	// std::cout << "default constractor called" << std::endl;
}

FixNumber::FixNumber(const float &nbr):value(0)
{
	// std::cout << "Float construcor called" << std::endl;
	// std::cout << "this float is " << nbr << std::endl;
	this->value = roundf(nbr * (1 << this->fractionalBit));
	// std::cout << "input value is " << this->value << std::endl;
}

FixNumber::FixNumber(const int &nbr)
{
	// std::cout << "Int constructor called" << std::endl;
	this->value = nbr << this->fractionalBit;
}

FixNumber::~FixNumber()
{
	// std::cout << "delimiter called" << std::endl;
}

FixNumber::FixNumber(const FixNumber &nbr):value(nbr.value)
{
	this->value = nbr.get_value();
}

FixNumber& FixNumber::operator=(const FixNumber &nbr)
{
	this->value = nbr.get_value();
	return (*this);
}

bool			FixNumber::operator>(FixNumber const &nbr) const
{
	return (this->get_value() > nbr.get_value());
}

bool			FixNumber::operator<(FixNumber const &nbr) const
{
	return (this->get_value() > nbr.get_value());
}

bool			FixNumber::operator>=(FixNumber const &nbr)
{
	return (this->get_value() >= nbr.get_value());
}

bool			FixNumber::operator<=(FixNumber const &nbr)
{
	return (this->get_value() <= nbr.get_value());
}

bool			FixNumber::operator==(FixNumber const &nbr)
{
	return (this->get_value() == nbr.get_value());
}

bool			FixNumber::operator!=(FixNumber const &nbr)
{
	return (this->get_value() != nbr.get_value());
}

FixNumber	FixNumber::operator+(FixNumber const &nbr)
{
	FixNumber	val(*this);
	
	val.set_value(this->get_value() + nbr.get_value());
	return (val);
}

FixNumber	FixNumber::operator-(FixNumber const &nbr)
{
	FixNumber	val(*this);
	
	val.set_value(this->get_value() - nbr.get_value());
	return (val);
}

FixNumber	FixNumber::operator*(FixNumber const &nbr)
{
	FixNumber	val(*this);
	long		tmp1;
	long		tmp2;

	tmp1 = (long)this->get_value();
	tmp2 = (long)nbr.get_value();
	val.set_value(tmp1 * tmp2 / (1 << this->fractionalBit));
	return (val);
}

FixNumber	FixNumber::operator/(FixNumber const &nbr)
{
	FixNumber	val(*this);
	long		tmp1;
	long		tmp2;

	tmp1 = (long)this->get_value();
	tmp2 = (long)nbr.get_value();
	val.set_value(tmp1 * (1 << this->fractionalBit) / tmp2);
	return (val);
}

FixNumber	FixNumber::operator++()
{
	this->value++;
	return (*this);
}

FixNumber	FixNumber::operator++(int)
{
	FixNumber tmp(*this);

	operator++();
	return (tmp);
}

FixNumber	FixNumber::operator--()
{
	this->value--;
	return (*this);
}

FixNumber	FixNumber::operator--(int)
{
	FixNumber tmp(*this);

	operator--();
	return (tmp);
}

std::ostream &operator<<(std::ostream &out, const FixNumber &tgt)
{
	out << tgt.toFloat();
	return (out);	
}

int	FixNumber::get_value() const
{
	return (this->value);
}

void	FixNumber::set_value(const int nbr)
{
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

FixNumber&	FixNumber::min(FixNumber &nb1, FixNumber &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

const FixNumber&	FixNumber::min(FixNumber const &nb1, FixNumber const &nb2)
{
	if (nb1 > nb2)
		return (nb2);
	return (nb1);
}

FixNumber &min(FixNumber &a, FixNumber &b)
{
	return (FixNumber::min(a, b));
}

FixNumber&	FixNumber::max(FixNumber &nb1, FixNumber &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

const FixNumber&	FixNumber::max(FixNumber const &nb1, FixNumber const &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

FixNumber &max(FixNumber &a, FixNumber &b)
{
	return (FixNumber::max(a, b));
}