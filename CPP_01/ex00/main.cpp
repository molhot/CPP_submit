/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:25:18 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 19:31:03 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	testzombi(Zombie test)
{
	test.makesound();
}

int main()
{
	std::string	zombie1;
	std::string	zombie2;

	std::cout << "input first zombiename" << std::endl;
	std::cin >> zombie1;
	// Zombie::randomChump(zombie1);
	// std::cout << "-----------------------" << std::endl;

	std::cout << "test copyconstructor" << std::endl;
	Zombie zom1(zombie1);
	Zombie zom2 = zom1;
	std::cout << "zom1 address is " << &zom1 << std::endl;
	std::cout << "zom2 address is " << &zom2 << std::endl;
	std::cout << "-----------------------" << std::endl;

	std::cout << "test operand overload" << std::endl;
	Zombie zom3;
	zom3 = zom2;

	std::cout << "out scope check" << std::endl;
	testzombi(zom1);

	std::cout << "-----------------------" << std::endl;
	
	Zombie *zom4 = newZombie("test");
	zom4->makesound();
	randomChump("test2");

	// std::cout << "input second zombiename" << std::endl;
	// std::cin >> zombie2;
	// Zombie::newZombie(zombie2);
}