/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:38:44 by user              #+#    #+#             */
/*   Updated: 2023/06/19 20:49:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
	std::cout << "President constructor called" << std::endl;
	this->_name = "Shruberry";
	this->_target = target;
	this->_signed = false;
	this->_grade4sign = 25;
	this->_grade4execute = 5;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "President destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &sub)
{
	std::cout << "President COPY constructor called" << std::endl;
	this->_name = sub.getName();
	this->_target = sub.getTarget();
	this->_signed = sub.get_Signstatus();
	this->_grade4sign = sub.get_Grade4Sign();
	this->_grade4execute = sub.get_Grade4excete();
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &sub)
{
	std::cout << "copy assignment called" << std::endl;
	if (this == &sub)
		return (*this);
	this->_name = sub.getName();
	this->_target = sub.getTarget();
	this->_signed = sub.get_Signstatus();
	this->_grade4sign = sub.get_Grade4Sign();
	this->_grade4execute = sub.get_Grade4excete();
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &sub) const
{
	if (this->get_Signstatus() == false)
		throw (AForm::NotSigned());
	if (sub.getGrade() > this->get_Grade4excete())
		throw (AForm::GradeTooLowException());
	std::cout << this->getName() << "has been pardoned by Zaphod" << std::endl;
}