/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:39:26 by user              #+#    #+#             */
/*   Updated: 2023/05/07 23:32:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyForm", target, 72, 45)
{
	std::cout << "Robotomy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &sub): Form(sub.getName(), sub.getTarget(), sub.get_Grade4Sign(), sub.get_Grade4excete())
{
	std::cout << "Robotomy COPY constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &sub)
{
	if (this == &sub)
		return (*this);
	this->Form::operator=(sub);
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