/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:46:12 by user              #+#    #+#             */
/*   Updated: 2023/06/09 11:43:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP

#include <iostream>

class WrongAnimal
{
    private:
        std::string _type;

    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal const &sub);
        WrongAnimal &operator=(WrongAnimal const &sub);
        void    makeSound()const;
        std::string get_Type()const;
        void    set_Type(std::string Type);
};

#endif