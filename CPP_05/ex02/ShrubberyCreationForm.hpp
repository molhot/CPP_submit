/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:41:10 by user              #+#    #+#             */
/*   Updated: 2023/05/07 23:11:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

#define ASCII_ART "\
       /42\\          \n\
      /    \\         \n\
     /\\*   *\\        \n\
    /\\O\\*   *\\       \n\
   /*/\\/\\/   *\\      \n\
  /\\O\\/\\*\\/   *\\     \n\
 /\\*\\/\\*\\/\\/   *\\   \n\
/\\O\\/\\/*/\\/O/   *\\   \n\
      |  t  |         \n\
      |  r  |         \n\
      |  e  |         \n\
      |  e  |     	  \n\
"

class ShrubberyCreationForm: public Form
{
	private:
		
	
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &sub);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const &sub);
		void	execute(Bureaucrat const &executor) const;
};

#endif