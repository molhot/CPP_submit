/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:18:47 by user              #+#    #+#             */
/*   Updated: 2023/06/13 01:10:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string _type;
        //virtual ~Animal();

    public:
        virtual ~Animal();
        // Animal(std::string type);
        //Animal();
        //Animal(Animal const &sub);
        //Animal &operator=(Animal const &sub);
        virtual void    makeSound()const = 0;
        std::string     getType()const;
};

#endif