/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:58:54 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/04 18:42:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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