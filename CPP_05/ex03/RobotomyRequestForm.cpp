/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:39:26 by user              #+#    #+#             */
/*   Updated: 2023/06/19 21:08:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
{
	this->_name = "RobotomyRequestForm";
	this->_target = target;
	this->_signed = false;
	this->_grade4sign = 72;
	this->_grade4execute = 45;
	std::cout << "Robotomy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &sub)
{
	this->_name = sub.getName();
	this->_target = sub.getTarget();
	this->_signed = sub.get_Signstatus();
	this->_grade4sign = sub.get_Grade4Sign();
	this->_grade4execute = sub.get_Grade4excete();
	std::cout << "Robotomy COPY constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &sub)
{
	if (this == &sub)
		return (*this);
	this->_name = sub.getName();
	this->_target = sub.getTarget();
	this->_signed = sub.get_Signstatus();
	this->_grade4sign = sub.get_Grade4Sign();
	this->_grade4execute = sub.get_Grade4excete();
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &sub) const
{
	if (this->get_Signstatus() == false)
		throw (Form::NotSigned());
	if (sub.getGrade() > this->get_Grade4excete())
		throw (Form::GradeTooLowException());
	std::cout << "\a";
	if (std::rand() % 2 == 0)
		std::cout << "I a...m... rob...o...." << std::endl;
	else
		std::cout << "I am still not robot!!" << std::endl;
}