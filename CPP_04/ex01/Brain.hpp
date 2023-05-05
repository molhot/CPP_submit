/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:15:39 by user              #+#    #+#             */
/*   Updated: 2023/05/05 18:21:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>

class Brain
{
    private:
        std::string *_ideas;
    
    public:
        Brain();
        ~Brain();
        Brain(Brain const &other_brain);
        Brain &operator=(Brain const &other_brain);
        std::string get_idea(size_t i);
        void set_idea(size_t i, std::string idea);
};

#endif