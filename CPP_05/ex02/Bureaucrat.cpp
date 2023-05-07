/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:37:50 by user              #+#    #+#             */
/*   Updated: 2023/05/07 23:03:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("no_name"), _grade(150)
{
	std::cout << "Breaucrat with no argment constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150)
{
	std::cout << "Breaucrat with argment constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << "Breaucrat constructor called" << std::endl;
	if (grade < 1)
	{
		std::cout << "constructor error (too high)" << std::endl;
		exit(1);
	}
	if (grade > 150)
	{
		std::cout << "constructor error (too low)" << std::endl;
		exit(1);
	}
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Breaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &sub): _name(sub._name), _grade(sub._grade)
{
	std::cout << "Breaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &sub)
{
	if (this == &sub)
		return (*this);
	this->_name = sub._name;
	this->_grade = sub._grade;
	return (*this);
}

std::string	Bureaucrat::getName()
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade()
{
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_grade - 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = this->_grade - 1;
}

void	Bureaucrat::increaseGrade(int grade)
{
	if (this->_grade - grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_grade - grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = this->_grade - grade;
}

void	Bureaucrat::decreaseGrade()
{
	if (this->_grade + 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = this->_grade + 1;
}

void	Bureaucrat::decreaseGrade(int grade)
{
	if (this->_grade + grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_grade + grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = this->_grade + grade;
}

//High error crass

void	Bureaucrat::executeForm(Form const &sub)
{
	try
	{
		sub.execute(*this);
		std::cout << *this << " executed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " cannnot executed" << std::endl;
	}
	
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	std::cout << "GradeTooHighException constructor called" << std::endl;
}

// Breaucrat::GradeTooHighException::~GradeTooHighException()
// {
// 	std::cout << "GradeTooHighException destructor called" << std::endl;
// }

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grede is over 1");
}

//Low error crass

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	std::cout << "GradeTooLowException constructor called" << std::endl;
}

// Breaucrat::GradeTooLowException::~GradeTooLowException()
// {
// 	std::cout << "GradeTooLowException destructor called" << std::endl;
// }

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grede is under 150");
}

//override output func

std::ostream &operator<<(std::ostream &out, Bureaucrat &tgt)
{
	out << tgt.getName() << ", bureaucrat grade " << tgt.getGrade();
	return (out);	
}
