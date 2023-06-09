/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:39:40 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 18:27:20 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <limits>
#include <iostream>

class Phonebook
{
    private:
		Contact	_contacts_[8];
		void	_addcontact_(void);
	
	public:
		Phonebook();
		~Phonebook();
		void	Manual(void);
		bool	addcontact(int i);
		void	showcontact(int i);
};