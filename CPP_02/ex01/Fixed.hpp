/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:05 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/27 21:52:28 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	FixNumber
{
	private:
		int					value;
		static	const	int	fractionalBit = 8;
	
	public:
		FixNumber();
		~FixNumber();
		FixNumber(const FixNumber &nbr);
		FixNumber&			operator=(const FixNumber &nbr);
		int					get_value();
		void				set_value(const int nbr);
};