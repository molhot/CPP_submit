/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:58:54 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/27 09:59:33 by mochitteiun      ###   ########.fr       */
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
		void		set_weapon(std::string weapon);
};