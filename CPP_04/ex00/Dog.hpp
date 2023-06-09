/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:46:28 by user              #+#    #+#             */
/*   Updated: 2023/06/09 11:16:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"

class Dog: public Animal
{
    private:

    public:
        Dog();
        ~Dog();
        Dog(Dog const &sub);
        Dog &operator=(Dog const &sub);
        void    makeSound() const;
};

#endif