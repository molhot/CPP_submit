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
		int					getRawBits(void) const;
		void				setRawBits(const int nbr);
		float				toFloat(void) const;
		int					toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &tgt);

#endif