/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:39:28 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 18:28:05 by mochitteiun      ###   ########.fr       */
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
    std::cin >> this->_firstname;
    std::cout << "input lastname" << std::endl;
    std::cin >> this->_lastname;
    std::cout << "input nickname" << std::endl;
    std::cin >> this->_nickname;
    std::cout << "input phonenumber" << std::endl;
    std::cin >> this->_phonenumber;
	if (ft_isdigit(this->_phonenumber) == false)
		return (false);
    std::cout << "input secret" << std::endl;
    std::cin >> this->_secret;
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
	std::cout << " | ";
    std::cout << this->_index;
	std::cout << " | ";
	show_wd_eight(this->_firstname);
	show_wd_eight(this->_nickname);
	show_wd_eight(this->_phonenumber);
	std::cout << std::endl;
}