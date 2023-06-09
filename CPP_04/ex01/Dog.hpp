/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:46:28 by user              #+#    #+#             */
/*   Updated: 2023/06/09 11:37:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal, public Brain
{
    private:
        Brain *_brain;

    public:
        Dog();
        ~Dog();
        Dog(Dog const &sub);
        Dog &operator=(Dog const &sub);
        void    makeSound() const;
        void    getIdea()const;
        void    setIdea(size_t i, std::string idea);
};

#endif