/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:39:17 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/07 23:22:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde(int num, std::string name)
{
	int		i;
	Zombie	*zombiehorde;

	if (num <= 0)
	{
		std::cout << "input plus num!" << std::endl;
		return (NULL);
	}
	try
	{
		zombiehorde = new Zombie[num];
	}
	catch(const std::exception& e)
	{
		std::cout << "new is missed" << std::endl;
		exit(1);
	}
	i = 0;
	while (i != num)
	{
		zombiehorde[i].namedzombie(name);
		zombiehorde[i].announce();
		//announce
		i++;
	}
	return (zombiehorde);
}