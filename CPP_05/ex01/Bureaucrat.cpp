/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:45:08 by user              #+#    #+#             */
/*   Updated: 2023/05/07 20:26:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("test user"), _grade(15)
{
	std::cout << "Bureaucrat with no argment constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(15)
{
	std::cout << "Bureaucrat with argment constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &sub): _name(sub._name), _grade(sub._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
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
	while (grade != 0)
	{
		this->_grade = this->_grade - 1;
		grade = grade - 1;
		if (this->_grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		if (this->_grade > 150)
			throw (Bureaucrat::GradeTooLowException());
	}
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
	while (grade != 0)
	{
		this->_grade = this->_grade + 1;
		grade = grade - 1;
		if (this->_grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		if (this->_grade > 150)
			throw (Bureaucrat::GradeTooLowException());
	}
}

//High error crass

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	std::cout << "GradeTooHighException constructor called" << std::endl;
}

// Bureaucrat::GradeTooHighException::~GradeTooHighException()
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

// Bureaucrat::GradeTooLowException::~GradeTooLowException()
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

void		Bureaucrat::signForm(Form &tgt)
{
	try
	{
		tgt.beSigned(*this);
		std::cout << "================================" << std::endl;
		std::cout << " << " << tgt.get_name() << " is signed by " << this->getName() << " >> " << std::endl;
		std::cout << "================================" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "===================================" << std::endl;
		std::cout << " << " << tgt.get_name() << " is NOT signed by " << this->getName() << " >> " << std::endl;
		std::cout << "===================================" << std::endl;
		std::cout << "| reason -> " << e.what() << " |" << std::endl;
		std::cout << "=========check=========" << std::endl;
	}
	
}