/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:05 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/09 22:39:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	Fixed_HPP
#define	Fixed_HPP

#include <iostream>
#include <cmath>
#include <stdbool.h>

class	Fixed
{
	private:
		int					value;
		static	const	int	fractionalBit = 8;
	
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &nbr);
		Fixed(const float &nbr);
		Fixed(const int &nbr);
		Fixed&			operator=(const Fixed &nbr);
		Fixed			operator+(Fixed const &nbr);
		Fixed			operator-(Fixed const &nbr);
		Fixed			operator*(Fixed const &nbr);
		Fixed			operator/(Fixed const &nbr);
		Fixed			&operator++();
		Fixed			operator++(int);
		Fixed			&operator--();
		Fixed			operator--(int);
		
		bool				operator>(Fixed const &nbr) const;
		bool				operator<(Fixed const &nbr) const;
		bool				operator>=(Fixed const &nbr);
		bool				operator<=(Fixed const &nbr);
		bool				operator==(Fixed const &nbr);
		bool				operator!=(Fixed const &nbr);
		int					getRawBits() const;
		void				setRawBits(const int nbr);
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed&			min(Fixed &nb1, Fixed &nb2);
		static const Fixed&			min(Fixed const &nb1, Fixed const &nb2);
		static Fixed&			max(Fixed &nb1, Fixed &nb2);
		static const Fixed&			max(Fixed const &nb1, Fixed const &nb2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &tgt);

#endif