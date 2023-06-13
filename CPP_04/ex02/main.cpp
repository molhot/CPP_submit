/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:14:04 by user              #+#    #+#             */
/*   Updated: 2023/06/13 23:11:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int error_new(size_t pos, Animal **anim)
{
    while (pos != 0)
    {
        delete anim[pos];
        pos--;
    }
    std::cout << "new is failed" << std::endl;
    return (1);
}

int main()
{
    //Animal some; Animal is Abstractclass so you can not make this instance
    Animal *anim[10];
    size_t  pos;
    size_t  idea_pos;

    std::cout << "prev test" << std::endl;
    std::cout << "-----------------//\\\\//\\\\//\\\\//\\\\//\\\\//\\\\-----------------" << std::endl;
    pos = 0;
    while (pos != 10)
    {
        if (pos % 2  == 1)
        {
            anim[pos] = new Cat();
            std::cout << anim[pos]->getType() << std::endl;
            //if you don't use dynamic cast, can not access to setIdea and getIdea
            //dynamic_cast<Cat *>(anim[pos])->setIdea(0, "brabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabrabra");
            if (anim[pos] == NULL)
                return (error_new(pos, anim));
        }
        else
        {
            anim[pos] = new Dog();
            if (anim[pos] == NULL)
                return (error_new(pos, anim));
        }
        pos++;
    }

    pos = 0;
    while (pos != 10)
    {
        //if you don't use virtual class, will call only animal deconstructor...
        delete anim[pos];
        pos++;
    }
    std::cout << std::endl;
    
    std::cout << "-----------------//\\\\//\\\\//\\\\//\\\\//\\\\//\\\\-----------------" << std::endl;
    std::cout << "cat test" << std::endl;
    std::cout << "-----------------//\\\\//\\\\//\\\\//\\\\//\\\\//\\\\-----------------" << std::endl;
    //prev fub check//
    
    Cat *cat = new Cat();
    idea_pos = 0;
    while (idea_pos != 100)
    {
        cat->setIdea(idea_pos, "chu-ru!!");
        idea_pos++;
    }
    cat->getIdea();

    std::cout << "-----------------//\\\\//\\\\//\\\\//\\\\//\\\\//\\\\-----------------" << std::endl;
    std::cout << "cat2 test" << std::endl;
    std::cout << "-----------------//\\\\//\\\\//\\\\//\\\\//\\\\//\\\\-----------------" << std::endl;
    Cat cat2(*cat);
    cat2.getIdea();

    std::cout << "-----------------//\\\\//\\\\//\\\\//\\\\//\\\\//\\\\-----------------" << std::endl;
    std::cout << "cat3 test" << std::endl;
    std::cout << "-----------------//\\\\//\\\\//\\\\//\\\\//\\\\//\\\\-----------------" << std::endl;
    Cat cat3;
    cat3 = cat2;
    cat3.getIdea();

    std::cout << "-----------------//\\\\//\\\\//\\\\//\\\\//\\\\//\\\\-----------------" << std::endl;
    std::cout << "cat4 test" << std::endl;
    std::cout << "-----------------//\\\\//\\\\//\\\\//\\\\//\\\\//\\\\-----------------" << std::endl;
    Cat *cat4 = new Cat();
    *cat4 = cat3;
    cat4->getIdea();

    delete cat;
    delete cat4;

    std::cout << "-----------------//\\\\//\\\\//\\\\//\\\\//\\\\//\\\\-----------------" << std::endl;
    std::cout << "dog testing" << std::endl;
    std::cout << "-----------------//\\\\//\\\\//\\\\//\\\\//\\\\//\\\\-----------------" << std::endl;

    Dog *dd = new Dog();
    idea_pos = 0;
    while (idea_pos != 100)
    {
        dd->setIdea(idea_pos, "chu-ru!!");
        idea_pos++;
    }
    Dog ee(*dd);
    ee.getIdea();

    Dog *kk = new Dog();
    idea_pos = 0;
    while (idea_pos != 100)
    {
        kk->setIdea(idea_pos, "BSDKJHKWD!!");
        idea_pos++;
    }
    ee = *kk;
    ee.getIdea();

    delete dd;
    delete kk;

    std::cout << "-----------------//\\\\//\\\\//\\\\//\\\\//\\\\//\\\\-----------------" << std::endl;
    std::cout << "can not instance check" << std::endl;
    std::cout << "-----------------//\\\\//\\\\//\\\\//\\\\//\\\\//\\\\-----------------" << std::endl;

    //Animal anim();
    //Animal anim("dog");

    //above, you can't implement code because abstract class!!
    system("leaks -q ex02");
}