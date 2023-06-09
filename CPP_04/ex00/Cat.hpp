/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:22:32 by user              #+#    #+#             */
/*   Updated: 2023/06/09 11:15:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"

class Cat: public Animal
{
    private:

    public:
        Cat();
        ~Cat();
        Cat(Cat const &sub);
        Cat &operator=(Cat const &sub);
        void    makeSound()const;
};

#endif