/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:22:32 by user              #+#    #+#             */
/*   Updated: 2023/06/09 11:50:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal, public Brain
{
    private:
        Brain *_brain;

    public:
        Cat();
        virtual ~Cat();
        Cat(Cat const &sub);
        Cat &operator=(Cat const &sub);
        void    makeSound()const;
        void    getIdea()const;
        void    setIdea(size_t i, std::string idea);
};

#endif