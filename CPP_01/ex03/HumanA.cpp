/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:58:46 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/27 00:07:45 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::~HumanA()
{
	
}

HumanA::HumanA(std::string namea, const Weapon& wep_a):name(namea), weapon_a(wep_a)
{
	//初期化を上記のように行わない（weapon_a(wep_a)）場合はweapon()という引数ナシの初期化が呼ばれる
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon_a.getType() << std::endl;
}