/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:22:35 by user              #+#    #+#             */
/*   Updated: 2023/06/13 01:09:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
    if (this->_brain == NULL)
    {
        std::cout << "new is missed" << std::endl;
        exit (1);
    }
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete(this->_brain);
}

Cat::Cat(Cat const &sub)
{
    std::cout << "Cat COPY_constructor called" << std::endl;
    this->_type = sub.getType();
    this->_brain = new Brain(*(sub._brain));
    
}

Cat& Cat::operator=(Cat const &sub)
{
    std::cout << "Cat operator called" << std::endl;
    if (this == &sub)
        return (*this);
    
    this->_type = sub._type;
    this->_brain = new Brain();
    if (this->_brain == NULL)
    {
        std::cout << "new is missed" << std::endl;
        exit (1);
    }
    //error
    //this->_brain = sub._brain;
    //not error
    *this->_brain = *sub._brain;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "two!...nya-" << std::endl;
}

void    Cat::getIdea() const
{
    size_t  pos;

    pos = 0;
    while (pos != 100)
    {
        std::cout << "Cat Idea " <<  pos + 1 << " is " << this->_brain->get_idea(pos) << std::endl;
        pos++;
    }
}

void    Cat::setIdea(size_t i, std::string idea)
{
    this->_brain->set_idea(i, idea);
}