/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:37:22 by user              #+#    #+#             */
/*   Updated: 2023/06/19 20:39:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Aform_HPP
#define Aform_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	protected:
		std::string _name;
		std::string	_target;
		bool		_signed;
		int			_grade4sign;
		int			_grade4execute;

	public:
		//Form(std::string name, std::string target, int sign_grade, int execute_grade);
		virtual ~AForm();
		//Form(Form const &sub);
		//Form& operator=(Form const &sub);
		void			beSigned(Bureaucrat const &sub);
		bool			get_Signstatus() const;
		std::string		getName() const;
		std::string		getTarget() const;
		int				get_Grade4Sign() const;
		int				get_Grade4excete() const;
		virtual	void			execute(Bureaucrat const &sub) const = 0;
		class	NotSigned: public std::exception
		{
			public:
				NotSigned();
				virtual const char* what() const throw();
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

#endif