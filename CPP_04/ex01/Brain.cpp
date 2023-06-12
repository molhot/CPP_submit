/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:15:37 by user              #+#    #+#             */
/*   Updated: 2023/06/13 00:16:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(): _ideas(new std::string[100])
{
    std::cout << "Brain constructor called" << std::endl;
    //_ideas = new std::string[100];
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
    delete[] this->_ideas;
}

Brain::Brain(Brain const &other_brain)
{
    size_t  length;

    std::cout << "Brain copyconstructor called" << std::endl;
    length = 0;
    while (length != 100)
    {
        this->_ideas[length] = other_brain._ideas[length];
        length++;
    }
}

Brain& Brain::operator=(Brain const &other_brain)
{
    size_t  length;

    std::cout << "Brain operator called" << std::endl;
    if (this == &other_brain)
        return (*this);
    length = 0;
    while (length != 100)
    {
        this->_ideas[length] = other_brain._ideas[length];
        length++;
    }
    return (*this);
}

std::string Brain::get_idea(size_t i)
{
    if (i > 100)
    {
        std::cout << "over ideas" << std::endl;
        std::cout << "so return ''" << std::endl;
        return ("");
    }
    return (this->_ideas[i]);
}

void Brain::set_idea(size_t i, std::string idea)
{
    if (i > 100)
    {
        std::cout << "over ideas" << std::endl;
        return ;
    }
    this->_ideas[i] = idea; 
}