/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:38:44 by user              #+#    #+#             */
/*   Updated: 2023/05/07 23:33:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentForm", target, 72, 45)
{
	std::cout << "President constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "President destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &sub): Form(sub.getName(), sub.getTarget(), sub.get_Grade4Sign(), sub.get_Grade4excete())
{
	std::cout << "President COPY constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &sub)
{
	if (this == &sub)
		return (*this);
	this->Form::operator=(sub);
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &sub) const
{
	if (this->get_Signstatus() == false)
		throw (Form::NotSigned());
	if (sub.getGrade() > this->get_Grade4excete())
		throw (Form::GradeTooLowException());
	std::cout << this->getName() << "has been pardoned by Zaphod" << std::endl;
}