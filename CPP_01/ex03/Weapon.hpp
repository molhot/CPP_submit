/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:59:02 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/07 23:34:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_HPP
#define Weapon_HPP

#include <iostream>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon();
		Weapon(std::string weapon);
		~Weapon();
		Weapon(const Weapon &weapon);
		Weapon &operator=(const Weapon &weapon);
		const std::string		&getType() const;
		void					setType(std::string type);
};

#endif