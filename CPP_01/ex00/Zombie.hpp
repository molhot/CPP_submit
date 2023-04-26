/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:55:56 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 19:21:59 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		Zombie(std::string name);
		Zombie(const Zombie &cpzombie);
		Zombie& operator=(const Zombie &cpzombie);
		~Zombie();
		void	makesound();
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);