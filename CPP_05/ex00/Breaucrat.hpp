/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Breaucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:45:11 by user              #+#    #+#             */
/*   Updated: 2023/05/06 11:51:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Breaucrat_HPP
#define Breaucrat_HPP

#include <iostream>

class Breaucrat
{
	private:
		std::string	_name;
		int			_grade;

	public:
		Breaucrat();
		Breaucrat(std::string name);
		Breaucrat(std::string name, int grade);
		~Breaucrat();
		Breaucrat(Breaucrat const &sub);
		Breaucrat &operator=(Breaucrat const &sub);
		std::string	getName();
		int			getGrade();
		void		increaseGrade();
		void		increaseGrade(int grade);
		void		decreaseGrade();
		void		decreaseGrade(int grade);

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

std::ostream &operator<<(std::ostream &out, Breaucrat &tgt);

#endif