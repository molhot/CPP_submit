/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:08 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/11 13:13:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_value(0)
{
	// std::cout << "default constractor called" << std::endl; //testで見辛すぎるので一旦消します
}

Fixed::Fixed(const float &nbr):_value(0)
{
	// std::cout << "Float construcor called" << std::endl;
	// std::cout << "this float is " << nbr << std::endl;
	this->_value = roundf(nbr * (1 << this->_fractionalBit));
	// std::cout << "input _value is " << this->_value << std::endl;
}

Fixed::Fixed(const int &nbr)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_value = nbr << this->_fractionalBit;
}

Fixed::~Fixed()
{
	// std::cout << "delimiter called" << std::endl;
}

Fixed::Fixed(const Fixed &nbr):_value(nbr._value)
{
	// std::cout << "copy constractor called" << std::endl;
	this->_value = nbr.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &nbr)
{
	// std::cout << "copy asaiment operator called" << std::endl;
	if (this == &nbr)
		return (*this);
	this->_value = nbr.getRawBits();
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

bool			Fixed::operator>=(Fixed const &nbr) const
{
	return (this->getRawBits() >= nbr.getRawBits());
}

bool			Fixed::operator<=(Fixed const &nbr) const
{
	return (this->getRawBits() <= nbr.getRawBits());
}

bool			Fixed::operator==(Fixed const &nbr) const
{
	return (this->getRawBits() == nbr.getRawBits());
}

bool			Fixed::operator!=(Fixed const &nbr) const
{
	return (this->getRawBits() != nbr.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &nbr) const
{
	Fixed	val(*this);
	
	val.setRawBits(this->getRawBits() + nbr.getRawBits());
	return (val);
}

Fixed	Fixed::operator-(Fixed const &nbr) const
{
	Fixed	val(*this);
	
	val.setRawBits(this->getRawBits() - nbr.getRawBits());
	return (val);
}

Fixed	Fixed::operator*(Fixed const &nbr) const
{
	Fixed	val(*this);
	long		tmp1;
	long		tmp2;

	tmp1 = (long)this->getRawBits();
	tmp2 = (long)nbr.getRawBits();
	val.setRawBits(tmp1 * tmp2 / (1 << this->_fractionalBit));
	return (val);
}

Fixed	Fixed::operator/(Fixed const &nbr) const
{
	Fixed	val(*this);
	long		tmp1;
	long		tmp2;

	tmp1 = (long)this->getRawBits();
	tmp2 = (long)nbr.getRawBits();
	val.setRawBits(tmp1 * (1 << this->_fractionalBit) / tmp2);
	return (val);
}

Fixed	&Fixed::operator++()
{
	this->_value++;
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
	this->_value--;
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
	return (this->_value);
}

void	Fixed::setRawBits(const int nbr)
{
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

Fixed&	Fixed::min(Fixed &nb1, Fixed &nb2)
{
	if (nb1 > nb2)
		return (nb2);
	return (nb1);
}

const Fixed&	Fixed::min(Fixed const &nb1, Fixed const &nb2)
{
	if (nb1 > nb2)
		return (nb2);
	return (nb1);
}

// Fixed &min(Fixed &a, Fixed &b)
// {
// 	return (Fixed::min(a, b));
// }

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

// Fixed &max(Fixed &a, Fixed &b)
// {
// 	return (Fixed::max(a, b));
// }
