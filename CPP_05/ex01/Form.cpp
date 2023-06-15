/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:43:45 by user              #+#    #+#             */
/*   Updated: 2023/06/16 00:27:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("test form"), _signed(false), _grade4sign(15), _grade4execute(15)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string name): _name(name), _signed(false), _grade4sign(15), _grade4execute(15)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string name, int sign, int execute): _name(name), _signed(false), _grade4sign(sign), _grade4execute(execute)
{
	std::cout << "Form constructor called" << std::endl;
	if (sign < 1)
		throw Bureaucrat::GradeTooHighException();
	if (sign > 150)
		throw Bureaucrat::GradeTooLowException();
	if (execute < 1)
		throw Bureaucrat::GradeTooHighException();
	if (execute > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(Form const &sub): _name(sub._name), _signed(sub._signed), _grade4sign(sub._grade4sign), _grade4execute(sub._grade4execute)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

Form& Form::operator=(Form const &sub)
{
	std::cout << "Form operand called" << std::endl;
	if (this == &sub)
		return (*this);
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
		throw Form::GradeTooLowException();
}

bool	Form::get_Signstatus() const
{
	return (this->_signed);
}

std::string	Form::get_name() const
{
	return (this->_name);
}

int	Form::get_Grade4Sign() const
{
	return (this->_grade4sign);
}

int Form::get_Grade4excete() const
{
	return (this->_grade4execute);
}

//High error crass

Form::GradeTooHighException::GradeTooHighException()
{
	std::cout << "GradeTooHighException constructor called" << std::endl;
}

// Bureaucrat::GradeTooHighException::~GradeTooHighException()
// {
// 	std::cout << "GradeTooHighException destructor called" << std::endl;
// }

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grede High");
}

//Low error crass

Form::GradeTooLowException::GradeTooLowException()
{
	std::cout << "GradeTooLowException constructor called" << std::endl;
}

// Bureaucrat::GradeTooLowException::~GradeTooLowException()
// {
// 	std::cout << "GradeTooLowException destructor called" << std::endl;
// }

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grede Low");
}

//override output func

std::ostream &operator<<(std::ostream &out, Form &tgt)
{
	out << "              ---------\n";
	out << "              | " + tgt.get_name() + " |\n";
	out << "----------------------------------------\n";
	out << "| sign score | " << tgt.get_Grade4Sign() << " | execute score | " << tgt.get_Grade4excete() << " |\n";
	out << "----------------------------------------\n";
	return (out);	
}