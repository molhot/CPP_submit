/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:37:12 by user              #+#    #+#             */
/*   Updated: 2023/06/19 21:05:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

void	Form::beSigned(Bureaucrat const &sub)
{
	if (sub.getGrade() <= this->_grade4sign)
	{
		std::cout << "this is signed!" << std::endl;
		this->_signed = true;
	}
	else
	{
		std::cout << "this is not satisfied the rule" << std::endl;
		this->_signed = false;
	}
}

bool	Form::get_Signstatus() const
{
	return (this->_signed);
}

std::string Form::getName() const
{
	return (this->_name);
}

std::string	Form::getTarget() const
{
	return (this->_target);
}

int	Form::get_Grade4Sign() const
{
	return (this->_grade4sign);
}

int Form::get_Grade4excete() const
{
	return (this->_grade4execute);
}

Form::NotSigned::NotSigned()
{
	std::cout << "NotSigned constructor called" << std::endl;
}

const char* Form::NotSigned::what() const throw()
{
	return ("Not Signed");
}

Form::GradeTooLowException::GradeTooLowException()
{
	std::cout << "GradeTooLowException constructor called" << std::endl;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Too Low Grade");
}

void	Form::execute(Bureaucrat const &sub) const
{
	if (this->get_Signstatus() == false)
		throw (Form::NotSigned());
	if (sub.getGrade() > this->get_Grade4excete())
		throw (Form::GradeTooLowException());
}