/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:23:38 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/27 18:46:37 by mochitteiun      ###   ########.fr       */
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
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" \
	<< std::endl;
}

void	Harl::info(void)
{
	std::cout << \
	"I cannot believe adding extra bacon costs more money. You didn’t put \
	enough bacon in my burger! If you did, I wouldn’t be asking for more!" \
	<< std::endl;
}

void	Harl::warning(void)
{
	std::cout << \
	"I think I deserve to have some extra bacon for free. I’ve been coming \
	forears whereas you started working here since last month." \
	<< std::endl;
}

void	Harl::error(void)
{
	std::cout << \
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
	size_t	position = 0;
	while (position < 4 && levels[position].compare(level) != 0)
		position++;
	if (position < 4)
		(this->*(levelfunc[position]))();
}