/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:22:32 by user              #+#    #+#             */
/*   Updated: 2023/06/08 22:31:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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