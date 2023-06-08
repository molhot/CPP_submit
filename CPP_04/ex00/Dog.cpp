/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:46:31 by user              #+#    #+#             */
/*   Updated: 2023/06/08 22:31:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &sub): Animal(sub._type)
{
    std::cout << "Dog COPY_constructor called" << std::endl;
}

Dog& Dog::operator=(Dog const &sub)
{
    std::cout << "Dog operator called" << std::endl;
    this->_type = sub._type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "one!" << std::endl;
}