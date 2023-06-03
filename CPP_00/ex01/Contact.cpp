/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:39:28 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/03 14:08:54 by user             ###   ########.fr       */
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

static bool	ft_isdigit(std::string sub)
{
	size_t  pos;

	pos = 0;
	while (sub[pos] != '\0')
	{
		if ('0' <= sub[pos] && sub[pos] <= '9')
			pos++;
		else
			return (false);
	}
	return (true);
}

bool	Contact::init(size_t index)
{
    this->_index = index + 1;
    std::cout << "input firstname" << std::endl;
	std::getline(std::cin, this->_firstname);
	std::cin.clear();
	if (this->_firstname == "")
	{
		std::cout << "empty can not allowed" << std::endl;
		return (false);
	}
	
    std::cout << "input lastname" << std::endl;
	std::getline(std::cin, this->_lastname);
	std::cin.clear();
	if (this->_lastname == "")
	{
		std::cout << "empty can not allowed" << std::endl;
		return (false);
	}
	
    std::cout << "input nickname" << std::endl;
	std::getline(std::cin, this->_nickname);
	std::cin.clear();
	if (this->_nickname == "")
	{
		std::cout << "empty can not allowed" << std::endl;
		return (false);
	}
	
    std::cout << "input phonenumber" << std::endl;
	std::getline(std::cin, this->_phonenumber);
	std::cin.clear();
	if (this->_phonenumber == "")
	{
		std::cout << "empty can not allowed" << std::endl;
		return (false);
	}
	if (ft_isdigit(this->_phonenumber) == false)
		return (false);
	if (this->_phonenumber.size() != 11)
	{
		std::cout << "phone number is must 11 size" << std::endl;
		return (false);
	}
	
    std::cout << "input secret" << std::endl;
	std::getline(std::cin, this->_secret);
	std::cin.clear();
	if (this->_secret == "")
	{
		std::cout << "empty can not allowed" << std::endl;
		return (false);
	}
	return (true);
}

static	void	show_wd_eight(std::string sub)
{
	size_t	pos;
	size_t	arg_len;
	size_t	empty_len;

	pos = 0;
	empty_len = 0;
	arg_len = sub.length();
	if (arg_len < 10)
	{
		empty_len = 10 - arg_len;
		while (empty_len != 0)
		{
			std::cout << " ";
			empty_len--;
		}
		std::cout << sub;
	}
	else if (arg_len == 10)
		std::cout << sub;
	else
	{
		std::cout << sub.substr(0,9);
		std::cout << ".";
	}
	std::cout << "|";
}

static	void	show_wd_eight(size_t sub_nbr)
{
	size_t		pos;
	size_t		arg_len;
	size_t		empty_len;
	std::string	sub;

	pos = 0;
	empty_len = 0;
	sub = std::to_string(sub_nbr);
	arg_len = sub.length();
	if (arg_len < 10)
	{
		empty_len = 10 - arg_len;
		while (empty_len != 0)
		{
			std::cout << " ";
			empty_len--;
		}
		std::cout << sub;
	}
	std::cout << "|";
}

void    Contact::content_show(void)
{
	std::cout << " >> |";
    // std::cout << this->_index;
	// std::cout << "|";
	show_wd_eight(this->_index);
	show_wd_eight(this->_firstname);
	show_wd_eight(this->_lastname);
	show_wd_eight(this->_nickname);
	std::cout << std::endl;
}