/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:39:28 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/05/27 22:04:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <limits>
#include <iostream>

Contact::Contact()
{
}

Contact::~Contact()
{
}

bool	Contact::init(size_t index)
{
    this->_index = index + 1;
    std::cout << "input firstname" << std::endl;
	std::getline(std::cin, this->_firstname);
	if (this->_firstname == "")
		return (false);
    std::cout << "input lastname" << std::endl;
	std::getline(std::cin, this->_lastname);
	if (this->_lastname == "")
		return (false);
    std::cout << "input nickname" << std::endl;
	std::getline(std::cin, this->_nickname);
	if (this->_nickname == "")
		return (false);
    std::cout << "input phonenumber" << std::endl;
	std::getline(std::cin, this->_phonenumber);
	if (this->_phonenumber == "")
		return (false);
	if (ft_isdigit(this->_phonenumber) == false)
		return (false);
    std::cout << "input secret" << std::endl;
	std::getline(std::cin, this->_secret);
	if (this->_secret == "")
		return (false);
	return (true);
}

static	void	show_wd_eight(std::string sub)
{
	size_t	pos;

	pos = 0;
	while (sub[pos] != '\0' && pos != 10)
	{
		std::cout << sub[pos];
		pos++;
	}
	if (sub[pos] != '\0')
		std::cout << " ... ";
	std::cout << " | ";
}

void    Contact::content_show(void)
{
	std::cout << " ";
    std::cout << this->_index;
	std::cout << " | ";
	show_wd_eight(this->_firstname);
	show_wd_eight(this->_nickname);
	show_wd_eight(this->_phonenumber);
	std::cout << std::endl;
}