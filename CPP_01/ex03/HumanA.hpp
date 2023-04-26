/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:58:49 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 22:17:34 by mochitteiun      ###   ########.fr       */
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
		void		set_weapon(std::string weapon);
};