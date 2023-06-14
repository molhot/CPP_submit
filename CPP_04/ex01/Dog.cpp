/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:46:31 by user              #+#    #+#             */
/*   Updated: 2023/06/14 16:02:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
    this->_brain = new Brain();
    if (this->_brain == NULL)
    {
        std::cout << "new is missed" << std::endl;
        exit (1);
    }
}

Dog::Dog(Dog const &sub): Animal(sub._type)
{
    std::cout << "Dog COPY_constructor called" << std::endl;
    this->_brain = new Brain(*(sub._brain));
}

Dog& Dog::operator=(Dog const &sub)
{
    std::cout << "Dog operator called" << std::endl;
    if (this == &sub)
        return (*this);
    delete(this->_brain);
    this->_type = sub._type;
    this->_brain = new Brain(*(sub._brain));
    if (this->_brain == NULL)
    {
        std::cout << "new is missed" << std::endl;
        exit (1);
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete(this->_brain);
}

void    Dog::makeSound() const
{
    std::cout << "one!" << std::endl;
}

void    Dog::getIdea() const
{
    size_t  pos;

    pos = 0;
    while (pos != 100)
    {
        std::cout << "Cat Idea " <<  pos + 1 << " is " << this->_brain->get_idea(pos) << std::endl;
        pos++;
    }
}

void    Dog::setIdea(size_t i, std::string idea)
{
    this->_brain->set_idea(i, idea);
}