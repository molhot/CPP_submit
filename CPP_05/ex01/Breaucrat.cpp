/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Breaucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:45:08 by user              #+#    #+#             */
/*   Updated: 2023/05/06 14:41:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Breaucrat.hpp"

Breaucrat::Breaucrat(): _name("no_name"), _grade(150)
{
	std::cout << "Breaucrat with no argment constructor called" << std::endl;
}

Breaucrat::Breaucrat(std::string name): _name(name), _grade(150)
{
	std::cout << "Breaucrat with argment constructor called" << std::endl;
}

Breaucrat::Breaucrat(std::string name, int grade): _name(name)
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

Breaucrat::~Breaucrat()
{
	std::cout << "Breaucrat destructor called" << std::endl;
}

Breaucrat::Breaucrat(Breaucrat const &sub): _name(sub._name), _grade(sub._grade)
{
	std::cout << "Breaucrat copy constructor called" << std::endl;
}

Breaucrat& Breaucrat::operator=(Breaucrat const &sub)
{
	if (this == &sub)
		return (*this);
	this->_name = sub._name;
	this->_grade = sub._grade;
	return (*this);
}

std::string	Breaucrat::getName()
{
	return (this->_name);
}

int	Breaucrat::getGrade() const
{
	return (this->_grade);
}

void	Breaucrat::increaseGrade()
{
	if (this->_grade - 1 < 1)
		throw (Breaucrat::GradeTooHighException());
	if (this->_grade - 1 > 150)
		throw (Breaucrat::GradeTooLowException());
	this->_grade = this->_grade - 1;
}

void	Breaucrat::increaseGrade(int grade)
{
	if (this->_grade - grade < 1)
		throw (Breaucrat::GradeTooHighException());
	if (this->_grade - grade > 150)
		throw (Breaucrat::GradeTooLowException());
	this->_grade = this->_grade - grade;
}

void	Breaucrat::decreaseGrade()
{
	if (this->_grade + 1 < 1)
		throw (Breaucrat::GradeTooHighException());
	if (this->_grade + 1 > 150)
		throw (Breaucrat::GradeTooLowException());
	this->_grade = this->_grade + 1;
}

void	Breaucrat::decreaseGrade(int grade)
{
	if (this->_grade + grade < 1)
		throw (Breaucrat::GradeTooHighException());
	if (this->_grade + grade > 150)
		throw (Breaucrat::GradeTooLowException());
	this->_grade = this->_grade + grade;
}

//High error crass

Breaucrat::GradeTooHighException::GradeTooHighException()
{
	std::cout << "GradeTooHighException constructor called" << std::endl;
}

// Breaucrat::GradeTooHighException::~GradeTooHighException()
// {
// 	std::cout << "GradeTooHighException destructor called" << std::endl;
// }

const char* Breaucrat::GradeTooHighException::what() const throw()
{
	return ("Grede is over 1");
}

//Low error crass

Breaucrat::GradeTooLowException::GradeTooLowException()
{
	std::cout << "GradeTooLowException constructor called" << std::endl;
}

// Breaucrat::GradeTooLowException::~GradeTooLowException()
// {
// 	std::cout << "GradeTooLowException destructor called" << std::endl;
// }

const char* Breaucrat::GradeTooLowException::what() const throw()
{
	return ("Grede is under 150");
}

//override output func

std::ostream &operator<<(std::ostream &out, Breaucrat &tgt)
{
	out << tgt.getName() << ", bureaucrat grade " << tgt.getGrade();
	return (out);	
}