/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:14:04 by user              #+#    #+#             */
/*   Updated: 2023/05/05 20:08:28 by user             ###   ########.fr       */
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
    Animal *anim[10];
    size_t  pos;
    size_t  idea_pos;

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
    //dynamic_cast<Cat *>(anim[1])->getIdea();

    Cat *cat = new Cat();
    idea_pos = 0;
    while (idea_pos != 100)
    {
        cat->setIdea(idea_pos, "chu-ru!!");
        idea_pos++;
    }
    cat->getIdea();

    pos = 0;
    while (pos != 10)
    {
        //if you don't use virtual class, will call only animal deconstructor...
        delete anim[pos];
        pos++;
    }

    delete cat;
    
    system("leaks -q ex01");
}