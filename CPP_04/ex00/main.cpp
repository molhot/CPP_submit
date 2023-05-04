/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:14:04 by user              #+#    #+#             */
/*   Updated: 2023/05/05 02:47:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makesound(); //will output the cat sound!
    j->makesound();
    meta->makesound();
    delete meta;
    delete j;
    delete i;

    const WrongAnimal* wrong_meta = new WrongAnimal();
    std::cout << wrong_meta->get_Type() << " " << std::endl;

    const WrongCat* wrong_cat = new WrongCat();
    std::cout << wrong_cat->get_Type() << " " << std::endl;

    delete wrong_meta;
    delete wrong_cat;

    return (0);
}