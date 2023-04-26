/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:38:29 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 19:42:00 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	*horde;

	horde = zombieHorde(3, "motitteiunon?");
	std::cout << "destruct move now" << std::endl;
	delete [] horde;
	return (0);
}