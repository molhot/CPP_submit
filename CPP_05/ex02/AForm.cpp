/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:37:12 by user              #+#    #+#             */
/*   Updated: 2023/05/07 23:08:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, std::string target, int sign, int execute): _name(name), _target(target), _grade4sign(sign), _grade4execute(execute), _signed(false)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(Form const &sub): _name(sub._name), _target(sub._target), _grade4sign(sub._grade4sign), _grade4execute(sub._grade4execute), _signed(sub._signed)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

Form& Form::operator=(Form const &sub)
{
	std::cout << "Form operand called" << std::endl;
	if (this == &sub)
		return (*this);
	this->_target = sub._target;
	this->_name = sub._name;
	this->_grade4sign = sub._grade4sign;
	this->_grade4execute = sub._grade4execute;
	this->_signed = sub._signed;
	return (*this);
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