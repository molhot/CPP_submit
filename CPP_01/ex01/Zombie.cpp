/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:38:46 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/04 18:32:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << this-> name << "is destructed" << std::endl;
}

void	Zombie::makesound()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::namedzombie(std::string name)
{
	this->name = name;
}

// void	Zombie::change_name(std::string re_name)
// {
// 	this->name = re_name;
// }