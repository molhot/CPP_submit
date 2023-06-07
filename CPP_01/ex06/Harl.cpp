/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:23:38 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/07 23:59:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void	Harl::debug(void)
{
	std::cout << \
	"[ DEBUG ]\n" << \
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" \
	<< std::endl;
}

void	Harl::info(void)
{
	std::cout << \
	"[ INFO ]\n" << \
	"I cannot believe adding extra bacon costs more money. You didn’t put \
	enough bacon in my burger! If you did, I wouldn’t be asking for more!" \
	<< std::endl;
}

void	Harl::warning(void)
{
	std::cout << \
	"[ WARNING ]\n" << \
	"I think I deserve to have some extra bacon for free. I’ve been coming \
	forears whereas you started working here since last month." \
	<< std::endl;
}

void	Harl::error(void)
{
	std::cout << \
	"[ ERROR ]\n" << \
	"This is unacceptable! I want to speak to the manager now" \
	<< std::endl;
}

void	Harl::complain(std::string level)
{
	Harl_func levelfunc[] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int	position = 0;
	while (position < 4 && levels[position].compare(level) != 0)
		position++;
	if (position < 4)
	{
		while (position != 4)
		{
			(this->*(levelfunc[position]))();
			position++;
		}
		return ;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	std::cout << "input [DEBUG, INFO, WARNING, ERROR]" << std::endl;
	// std::cout << "here" << std::endl;
	// try
	// {
	// 	(this->*(levelfunc[position]))();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << "no matching" << std::endl;
	// }これではいけない　詳しくはGPTに聞いて欲しいがキャッチしているエラーの種類が違うためである
}