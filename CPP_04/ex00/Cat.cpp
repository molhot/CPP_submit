/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:22:35 by user              #+#    #+#             */
/*   Updated: 2023/06/08 22:31:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &sub): Animal(sub._type)
{
    std::cout << "Cat COPY_constructor called" << std::endl;
}

Cat& Cat::operator=(Cat const &sub)
{
    std::cout << "Cat operator called" << std::endl;
    this->_type = sub._type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "two!...nya-" << std::endl;
}