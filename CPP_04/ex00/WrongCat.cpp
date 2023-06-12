/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:46:15 by user              #+#    #+#             */
/*   Updated: 2023/06/13 00:01:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("GGGGGAT")
{
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &sub)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->set_Type(sub.get_Type());
}

WrongCat& WrongCat::operator=(WrongCat const &sub)
{
    std::cout << "WrongCat operator called" << std::endl;
    if (this == &sub)
        return (*this);
    this->set_Type(sub.get_Type());
    return (*this);
}

void    WrongCat::makeSound()const
{
    std::cout << "ABATAKETABURA" << std::endl;
}