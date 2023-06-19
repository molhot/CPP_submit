/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:37:12 by user              #+#    #+#             */
/*   Updated: 2023/06/19 20:46:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

void	AForm::beSigned(Bureaucrat const &sub)
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

bool	AForm::get_Signstatus() const
{
	return (this->_signed);
}

std::string AForm::getName() const
{
	return (this->_name);
}

std::string	AForm::getTarget() const
{
	return (this->_target);
}

int	AForm::get_Grade4Sign() const
{
	return (this->_grade4sign);
}

int AForm::get_Grade4excete() const
{
	return (this->_grade4execute);
}

AForm::NotSigned::NotSigned()
{
	std::cout << "NotSigned constructor called" << std::endl;
}

const char* AForm::NotSigned::what() const throw()
{
	return ("Not Signed");
}

AForm::GradeTooLowException::GradeTooLowException()
{
	std::cout << "GradeTooLowException constructor called" << std::endl;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Too Low Grade");
}

void	AForm::execute(Bureaucrat const &sub) const
{
	if (this->get_Signstatus() == false)
		throw (AForm::NotSigned());
	if (sub.getGrade() > this->get_Grade4excete())
		throw (AForm::GradeTooLowException());
}