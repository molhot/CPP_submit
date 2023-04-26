/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:48:39 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/27 01:30:24 by mochitteiun      ###   ########.fr       */
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
	HumanB	alice("alice", &alicewep);
	HumanB	alice_n("alice_n");
	alice.attack();
	alice_n.attack();
}