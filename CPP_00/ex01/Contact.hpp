/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:39:31 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 18:19:23 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "utils.hpp"

class Contact
{
    private:
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _phonenumber;
        std::string _secret;
        size_t      _index;

	public:
		Contact();
		~Contact();
        bool        init(size_t index);
        void        content_show();
};