/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:58:46 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/07 23:42:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string namea, const Weapon& wep_a):weapon_a(wep_a), name(namea)
{
	//初期化を上記のように行わない（weapon_a(wep_a)）場合はweapon()という引数ナシの初期化が呼ばれる
}

HumanA::~HumanA()
{
	
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon_a.getType() << std::endl;
}

void	HumanA::set_weapon(const Weapon &some)
{
	std::cout << some.getType() << std::endl;
	this->weapon_a = some;
}