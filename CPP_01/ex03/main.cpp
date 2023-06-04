/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:48:39 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/04 18:50:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	Weapon	bobwep = Weapon("tile");
	HumanA	bob("bob", bobwep);
	//HumanA	bob_n("bob");
	
	bob.attack();
	//bob_n.attack();

	Weapon	alicewep = Weapon("camera");
	HumanB	alice("alice", alicewep);
	HumanB	alice_n("alice_n");
	alice.attack();
	alice_n.attack();

	std::cout << "~~~~~~" << std::endl;

	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club"); bob.attack();
	}

	std::cout << "~~~~~~" << std::endl;
	
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}