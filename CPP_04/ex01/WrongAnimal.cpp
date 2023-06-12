/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:46:08 by user              #+#    #+#             */
/*   Updated: 2023/06/13 00:09:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &sub): _type(sub._type)
{
    std::cout << "WrongAnimal COPY_constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &sub)
{
    std::cout << "WrongAnimal operator called" << std::endl;
    if (this == &sub)
        return (*this);
    this->_type = sub._type;
    return (*this);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "nantyarakantyara" << std::endl;
}

std::string WrongAnimal::get_Type() const
{
    return (this->_type);
}

void WrongAnimal::set_Type(std::string type)
{
    this->_type = type;
}