/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:58:49 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/07 23:40:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon		weapon_a;
		std::string	name;

	public:
		HumanA(std::string name, const Weapon& wep_a);
		~HumanA();
		void		attack();
		void		set_weapon(const Weapon &some);
};