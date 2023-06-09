/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:46:18 by user              #+#    #+#             */
/*   Updated: 2023/06/09 11:17:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
#define WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    private:
        
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(WrongCat const &sub);
        WrongCat &operator=(WrongCat const &sub);
        void    makeSound()const;
};

#endif