/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:14:04 by user              #+#    #+#             */
/*   Updated: 2023/06/13 00:04:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "subject test" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << "subject test end" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "                  " << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;

    std::cout << "wronganimal test" << std::endl;
    const WrongAnimal* wrong_meta = new WrongAnimal();
    std::cout << wrong_meta->get_Type() << " " << std::endl;
    wrong_meta->makeSound();

    const WrongCat* wrong_cat = new WrongCat();
    std::cout << wrong_cat->get_Type() << " " << std::endl;
    wrong_cat->makeSound();
    std::cout << "wrong test end" << std::endl;

    delete wrong_meta;
    delete wrong_cat;

    std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "                  " << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;

    return (0);
}