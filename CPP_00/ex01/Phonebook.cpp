/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:39:37 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 16:20:05 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <limits>
#include <iostream>

Phonebook::Phonebook()
{
}

Phonebook::~Phonebook()
{
}

void    Phonebook::Manual(void)
{
    std::cout << "this is phonebook app!" << std::endl;
    std::cout << "you can use three function" << std::endl;
    std::cout << "1 ADD 2 SEARCH 3 EXIT" << std::endl;
}

void    Phonebook::addcontact(int i)
{
    this->_contacts_[i % 8].init(i);
}

void    Phonebook::showcontact(int i)
{
	i = i - 1;
    this->_contacts_[i % 8].content_show();
}