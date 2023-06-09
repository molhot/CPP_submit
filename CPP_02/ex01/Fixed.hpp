/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:05 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/09 19:14:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	Fixed_HPP
#define	Fixed_HPP

#include <iostream>
#include <cmath>

class	FixNumber
{
	private:
		int					value;
		static	const	int	fractionalBit = 8;
	
	public:
		FixNumber();
		~FixNumber();
		FixNumber(const FixNumber &nbr);
		FixNumber(const float &nbr);
		FixNumber(const int &nbr);
		FixNumber&			operator=(const FixNumber &nbr);
		int					getRawBits(void) const;
		void				setRawBits(const int nbr);
		float				toFloat(void) const;
		int					toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const FixNumber &tgt);

#endif