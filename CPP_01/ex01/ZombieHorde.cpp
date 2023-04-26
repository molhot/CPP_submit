/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:39:17 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 19:39:21 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde(int num, std::string name)
{
	int		i;
	Zombie	*zombiehorde;

	zombiehorde = new Zombie[num];
	i = 0;
	while (i != num)
	{
		zombiehorde[i].namedzombie(name);
		zombiehorde[i].makesound();
		i++;
	}
	return (zombiehorde);
}