/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:05 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/04 15:36:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <float.h>

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
		int					getRawBits();
		void				setRawBits(const int nbr);
		float				toFloat(void) const;
		int					toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const FixNumber &tgt);