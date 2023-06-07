/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:58:51 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/07 00:58:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	
}

HumanB::~HumanB()
{
	
}

HumanB::HumanB(std::string namea):name(namea)
{
	//初期化を上記のように行わない（weapon_a(wep_a)）場合はweapon()という引数ナシの初期化が呼ばれる
	this->weapon_b = NULL;
}

HumanB::HumanB(std::string namea, Weapon &wep_b):weapon_b(&wep_b), name(namea)
{
	this->weapon_b->setType(wep_b.getType());
	//std::cout << "weapon is " << this->weapon_b << std::endl;
	//std::cout << this->name << " attacks with their " << (*(this->weapon_b)).getType() << std::endl;
	//初期化を上記のように行わない（weapon_a(wep_a)）場合はweapon()という引数ナシの初期化が呼ばれる
}

void	HumanB::attack()
{
	if (this->weapon_b == NULL)
		std::cout << "no... weapon... " << std::endl;
	else
	{
		//std::cout << "weapon is " << this->weapon_b << std::endl;
		std::cout << this->name << " attacks with their " << (*(this->weapon_b)).getType() << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &some)
{
	std::cout << some.getType() << std::endl;
	this->weapon_b = &some;
}