/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:05 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/09 23:22:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	Fixed_HPP
#define	Fixed_HPP

#include <iostream>

class	Fixed
{
	private:
		int					_value;
		static	const	int	_fractionalBit = 8;
	
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &nbr);
		Fixed&			operator=(const Fixed &nbr);
		int					getRawBits(void) const;
		void				setRawBits(const int nbr);
};

#endif