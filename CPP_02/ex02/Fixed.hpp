/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:05 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/29 20:19:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <float.h>
#include <stdbool.h>

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
		FixNumber			operator+(FixNumber const &nbr);
		FixNumber			operator-(FixNumber const &nbr);
		FixNumber			operator*(FixNumber const &nbr);
		FixNumber			operator/(FixNumber const &nbr);
		FixNumber			operator++();
		FixNumber			operator++(int);
		FixNumber			operator--();
		FixNumber			operator--(int);
		
		bool				operator>(FixNumber const &nbr) const;
		bool				operator<(FixNumber const &nbr) const;
		bool				operator>=(FixNumber const &nbr);
		bool				operator<=(FixNumber const &nbr);
		bool				operator==(FixNumber const &nbr);
		bool				operator!=(FixNumber const &nbr);
		int					get_value() const;
		void				set_value(const int nbr);
		float				toFloat(void) const;
		int					toInt(void) const;
		static FixNumber&			min(FixNumber &nb1, FixNumber &nb2);
		static const FixNumber&			min(FixNumber const &nb1, FixNumber const &nb2);
		static FixNumber&			max(FixNumber &nb1, FixNumber &nb2);
		static const FixNumber&			max(FixNumber const &nb1, FixNumber const &nb2);
};

std::ostream &operator<<(std::ostream &out, const FixNumber &tgt);