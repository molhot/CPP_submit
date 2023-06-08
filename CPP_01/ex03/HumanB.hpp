/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:58:54 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/08 23:36:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP
#define HumanB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon		*weapon_b;
		std::string	name;

	public:
		HumanB();
		HumanB(std::string name, Weapon &wep_b);
		HumanB(std::string name);
		~HumanB();
		void		attack();
		void		setWeapon(Weapon &some);
};

#endif