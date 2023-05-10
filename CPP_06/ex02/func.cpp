/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:00:21 by user              #+#    #+#             */
/*   Updated: 2023/05/10 21:36:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.hpp"

Base*	generate()
{
	int	random_num;

	srand(time(NULL));
	random_num = rand() % 3;
	if (random_num == 0)
	{
		std::cout << "making A class!" << std::endl;
		std::cout << std::endl;
		return (new A());
	}
	else if (random_num == 1)
	{
		std::cout << "making B class!" << std::endl;
		std::cout << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "making C class!" << std::endl;
		std::cout << std::endl;
		return (new C());
	}
}

void	identify(Base *p)
{
	//dynamic cast is return subject address ,but if cast missed return nullptr
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "this is A!" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "this is B! ! !" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "this is C! ! ! ! !" << std::endl;
	else
		std::cout << "??" << std::endl;
}

void	identify(Base& p)
{
	//dynamic cast (with reference) is throwing error ,if cast is missed
	if (&p == nullptr)
	{
		std::cout << "this is not correct !" << std::endl;
		return ;
	}
	try
	{
		A& tmp_a = dynamic_cast<A&>(p);
		std::cout << "this is A" << std::endl;
	}
	catch(const std::exception& e)
	{
		
	}
	try
	{
		B& tmp_b = dynamic_cast<B&>(p);
		std::cout << "this is B" << std::endl;
	}
	catch(const std::exception& e)
	{
		
	}
	try
	{
		C& tmp_c = dynamic_cast<C&>(p);
		std::cout << "this is C" << std::endl;
	}
	catch(const std::exception& e)
	{
		
	}
}