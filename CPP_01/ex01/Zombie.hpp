/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:39:00 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/07 23:07:00 by user             ###   ########.fr       */
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
		void	announce();
		//void	change_name(std::string);
};

Zombie*	zombieHorde(int num, std::string name);