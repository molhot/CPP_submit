/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:39:00 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 19:39:03 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		~Zombie();
		void	namedzombie(std::string name);
		void	makesound();
};

Zombie*	zombieHorde(int num, std::string name);