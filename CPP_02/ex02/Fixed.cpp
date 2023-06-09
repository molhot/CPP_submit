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
	// std::cout << "default constractor called" << std::endl;
}

Fixed::Fixed(const float &nbr):value(0)
{
	// std::cout << "Float construcor called" << std::endl;
	// std::cout << "this float is " << nbr << std::endl;
	this->value = roundf(nbr * (1 << this->fractionalBit));
	// std::cout << "input value is " << this->value << std::endl;
}

Fixed::Fixed(const int &nbr)
{
	// std::cout << "Int constructor called" << std::endl;
	this->value = nbr << this->fractionalBit;
}

Fixed::~Fixed()
{
	// std::cout << "delimiter called" << std::endl;
}

Fixed::Fixed(const Fixed &nbr):value(nbr.value)
{
	this->value = nbr.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &nbr)
{
	if (this == &nbr)
		return (*this);
	this->value = nbr.getRawBits();
	return (*this);
}

bool			Fixed::operator>(Fixed const &nbr) const
{
	return (this->getRawBits() > nbr.getRawBits());
}

bool			Fixed::operator<(Fixed const &nbr) const
{
	return (this->getRawBits() < nbr.getRawBits());
}

bool			Fixed::operator>=(Fixed const &nbr)
{
	return (this->getRawBits() >= nbr.getRawBits());
}

bool			Fixed::operator<=(Fixed const &nbr)
{
	return (this->getRawBits() <= nbr.getRawBits());
}

bool			Fixed::operator==(Fixed const &nbr)
{
	return (this->getRawBits() == nbr.getRawBits());
}

bool			Fixed::operator!=(Fixed const &nbr)
{
	return (this->getRawBits() != nbr.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &nbr)
{
	Fixed	val(*this);
	
	val.setRawBits(this->getRawBits() + nbr.getRawBits());
	return (val);
}

Fixed	Fixed::operator-(Fixed const &nbr)
{
	Fixed	val(*this);
	
	val.setRawBits(this->getRawBits() - nbr.getRawBits());
	return (val);
}

Fixed	Fixed::operator*(Fixed const &nbr)
{
	Fixed	val(*this);
	long		tmp1;
	long		tmp2;

	tmp1 = (long)this->getRawBits();
	tmp2 = (long)nbr.getRawBits();
	val.setRawBits(tmp1 * tmp2 / (1 << this->fractionalBit));
	return (val);
}

Fixed	Fixed::operator/(Fixed const &nbr)
{
	Fixed	val(*this);
	long		tmp1;
	long		tmp2;

	tmp1 = (long)this->getRawBits();
	tmp2 = (long)nbr.getRawBits();
	val.setRawBits(tmp1 * (1 << this->fractionalBit) / tmp2);
	return (val);
}

Fixed	&Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);

	operator++();
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);

	operator--();
	return (tmp);
}

std::ostream &operator<<(std::ostream &out, const Fixed &tgt)
{
	out << tgt.toFloat();
	return (out);	
}

int	Fixed::getRawBits() const
{
	return (this->value);
}

void	Fixed::setRawBits(const int nbr)
{
	this->value = nbr;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << this->fractionalBit));
}

int	Fixed::toInt(void) const
{
	return (this->value / (1 << this->fractionalBit));
}

Fixed&	Fixed::min(Fixed &nb1, Fixed &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

const Fixed&	Fixed::min(Fixed const &nb1, Fixed const &nb2)
{
	if (nb1 > nb2)
		return (nb2);
	return (nb1);
}

Fixed &min(Fixed &a, Fixed &b)
{
	return (Fixed::min(a, b));
}

Fixed&	Fixed::max(Fixed &nb1, Fixed &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

const Fixed&	Fixed::max(Fixed const &nb1, Fixed const &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

Fixed &max(Fixed &a, Fixed &b)
{
	return (Fixed::max(a, b));
}
