/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:18:49 by user              #+#    #+#             */
/*   Updated: 2023/06/08 22:31:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal desstructor called" << std::endl;
}

Animal::Animal(Animal const &sub): _type(sub._type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(Animal const &sub)
{
    std::cout << "Animal operator called" << std::endl;
    this->_type = sub._type;
    return (*this);
}

void    Animal::makeSound() const
{
    std::cout << "?" << std::endl;
}

std::string    Animal::getType() const
{
    return (this->_type);
}