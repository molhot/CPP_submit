/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:53:28 by user              #+#    #+#             */
/*   Updated: 2023/06/08 22:03:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    private:
        
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap const &other);
        FragTrap &operator=(FragTrap const &other);
        ~FragTrap();
        void    highFivesGuys(void);
};