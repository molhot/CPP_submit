/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:00:21 by user              #+#    #+#             */
/*   Updated: 2023/06/24 02:56:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.hpp"

Base*	generate()
{
	int	random_num;

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	random_num = std::rand() % 3;
	if (random_num == 0)
	{
		std::cout << "=================" << std::endl;
		std::cout << "|making A class!|" << std::endl;
		std::cout << "=================" << std::endl;
		return (new A());
	}
	else if (random_num == 1)
	{
		std::cout << "=================" << std::endl;
		std::cout << "|making B class!|" << std::endl;
		std::cout << "=================" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "=================" << std::endl;
		std::cout << "|making C class!|" << std::endl;
		std::cout << "=================" << std::endl;
		return (new C());
	}//すきに実装しろと書いてあるのでC++11も使っていいと判断
}

void	identify(Base *p)
{
	//dynamic cast is return subject address ,but if cast missed return nullptr
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "this is A!" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "this is B! ! !" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "this is C! ! ! ! !" << std::endl;
	else
		std::cout << "what is ... this ... ??" << std::endl;
}

void	identify(Base& p)
{
	//dynamic cast (with reference) is throwing error ,if cast is missed
	try
	{
		A& tmp_a = dynamic_cast<A&>(p);
		(void)tmp_a;
		std::cout << "this is A" << std::endl;
	}
	catch(const std::exception& e)
	{
		//std::cout << "cast (A) is missed" << std::endl;
	}
	try
	{
		B& tmp_b = dynamic_cast<B&>(p);
		(void)tmp_b;
		std::cout << "this is B" << std::endl;
	}
	catch(const std::exception& e)
	{
		//std::cout << "cast (B) is missed" << std::endl;
	}
	try
	{
		C& tmp_c = dynamic_cast<C&>(p);
		(void)tmp_c;
		std::cout << "this is C" << std::endl;
	}
	catch(const std::exception& e)
	{
		//std::cout << "cast (C) is missed" << std::endl;
	}
}