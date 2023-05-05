/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:18:47 by user              #+#    #+#             */
/*   Updated: 2023/05/05 18:41:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        Animal(Animal const &sub);
        Animal &operator=(Animal const &sub);
        virtual void    makesound()const;
        std::string     getType()const;
};

#endif