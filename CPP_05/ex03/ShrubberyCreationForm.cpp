/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:40:38 by user              #+#    #+#             */
/*   Updated: 2023/05/07 23:16:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("Shruberry", target, 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &sub): Form(sub.getName(), sub.getTarget(), sub.get_Grade4Sign(), sub.get_Grade4excete())
{
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &sub)
{
	if (this == &sub)
		return (*this);
	this->Form::operator=(sub);
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string filename;

	if (this->get_Signstatus() == false)
		throw (Form::NotSigned());
	if (executor.getGrade() > this->get_Grade4excete())
		throw (Form::GradeTooLowException());
	filename = this->getTarget() + "_shrubbery";
	std::ofstream file(filename);
	if (file.is_open() == false)
	{
		std::cout << "file is not open" << std::endl;
		exit(1);
	}
	file << ASCII_ART;
}