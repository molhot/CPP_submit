/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:43:41 by user              #+#    #+#             */
/*   Updated: 2023/06/16 00:20:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include <stdbool.h>
#include "Bureaucrat.hpp"


class Form
{
	private:
		std::string _name;
		bool		_signed;
		int			_grade4sign;
		int			_grade4execute;

	public:
		Form();
		Form(std::string name);
		Form(std::string name, int sign_grade, int execute_grade);
		~Form();
		Form(Form const &sub);
		Form& operator=(Form const &sub);
		void	beSigned(Bureaucrat const &sub);
		bool	get_Signstatus() const;
		std::string	get_name() const;
		int		get_Grade4Sign() const;
		int		get_Grade4excete() const;

		class GradeTooHighException: public std::exception
		{
			public:
				GradeTooHighException();
				//~GradeTooHighException();
				virtual const char* what() const throw();//not recommend?
				//virtual const char* what() const noexcept; over C++11 version
		};
		class GradeTooLowException: public std::exception
		{
			public:
				GradeTooLowException();
				//~GradeTooLowException();
				virtual const char* what() const throw();//not recommend?
				//virtual const char* what() const noexcept; over C++11 version
		};
};

std::ostream &operator<<(std::ostream &out, Form &tgt);

#endif