/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:38:29 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/07 23:30:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// void	change_test(Zombie *test)
// {
// 	test[1].change_name("change");
// }

int main()
{
	Zombie	*horde;

	horde = zombieHorde(10, "motitteiunon?");
	//change_test(horde);
	//horde[1].makesound();
	std::cout << "destruct move now" << std::endl;
	delete [] horde;

	//system("leaks ex01"); //leaks check
	return (0);
}