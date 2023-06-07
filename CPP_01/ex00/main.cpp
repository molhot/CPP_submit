/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:25:18 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/07 23:27:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	testzombi(Zombie test)
{
	test.announce();
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
	zom4->announce();
	randomChump("test2");
	delete zom4;

	// std::cout << "input second zombiename" << std::endl;
	// std::cin >> zombie2;
	// Zombie::newZombie(zombie2);
	system("leaks -q ex00");
}