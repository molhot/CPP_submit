/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:39:31 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/03 14:11:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

class Contact
{
    private:
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _phonenumber;
        std::string _secret;
        size_t      _index;
        bool        ft_isdigit(std::string sub);

	public:
		Contact();
		~Contact();
        bool        init(size_t index);
        void        content_show();
};