/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:40:38 by user              #+#    #+#             */
/*   Updated: 2023/06/19 20:54:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
	this->_name = "Shruberry";
	this->_target = target;
	this->_signed = false;
	this->_grade4sign = 145;
	this->_grade4execute = 137;
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &sub)
{
	this->_name = sub.getName();
	this->_target = sub.getTarget();
	this->_signed = sub.get_Signstatus();
	this->_grade4sign = sub.get_Grade4Sign();
	this->_grade4execute = sub.get_Grade4excete();
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &sub)
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

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string filename;

	if (this->get_Signstatus() == false)
		throw (AForm::NotSigned());
	if (executor.getGrade() > this->get_Grade4excete())
		throw (AForm::GradeTooLowException());
	filename = this->getTarget() + "_shrubbery";
	std::ofstream file(filename);
	if (file.is_open() == false)
	{
		std::cout << "file is not open" << std::endl;
		return ;
	}
	file << ASCII_ART;
	file.close();
}